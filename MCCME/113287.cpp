#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
};

struct Compressor {
    unordered_map<int, int> compressed;
    vector<int> decompressed;

    void insert(int value) {
        decompressed.push_back(value);
    }

    void prepare() {
        sort(decompressed.begin(), decompressed.end());
        decompressed.erase(unique(decompressed.begin(), decompressed.end()), decompressed.end());
        for (int i = 0; i < decompressed.size(); i++)
            compressed[decompressed[i]] = i;
    }

    int size() {
        return compressed.size();
    }

    int compress(int value) {
        return compressed[value];
    }

    int decompress(int value) {
        return decompressed[value];
    }
};

struct Event {
    enum { BEGIN, END } type;
    int x, y1, y2;

    bool operator < (const Event &that) const {
        if (x != that.x)
            return x < that.x;
        return type < that.type;
    }
};

struct SegmentTree {
    struct Data {
        int minValue = 0, minCount = 1, delta = 0;

        Data() {}

        Data(Data &l, Data &r) {
            if (l.minValue < r.minValue) {
                *this = l;
            } else if (l.minValue > r.minValue) {
                *this = r;
            } else {
                minValue = l.minValue;
                minCount = l.minCount + r.minCount;
            }
        }

        bool hasDelta() {
            return delta;
        }

        int getDelta() {
            return delta;
        }

        void changeDelta(int change) {
            delta += change;
        }

        void applyDelta(int vl, int vr) {
            minValue += delta;
            delta = 0;
        }
    };

    Compressor *compressor;
    int size;
    vector<Data> t;

    void build(int v, int vl, int vr) {
        if (vl == vr) {
            t[v].minCount = compressor->decompress(vl + 1) - compressor->decompress(vl);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm);
        build(2 * v + 2, vm + 1, vr);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    void push(int v, int vl, int vr) {
        if (t[v].hasDelta()) {
            if (vl != vr) {
                int vm = vl + (vr - vl) / 2;
                t[2 * v + 1].changeDelta(t[v].getDelta());
                t[2 * v + 2].changeDelta(t[v].getDelta());
            }
            t[v].applyDelta(vl, vr);
        }
    }

    void modify(int v, int vl, int vr, int l, int r, int delta) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            t[v].changeDelta(delta);
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, delta);
        modify(2 * v + 2, vm + 1, vr, l, r, delta);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(Compressor &compressor) : compressor(&compressor), size(compressor.size() - 1), t(4 * size) {
        build(0, 0, size - 1);
    }

    int getZeroCount() {
        return t[0].minValue ? 0 : t[0].minCount;
    }

    void add(int l, int r, int delta) {
        modify(0, 0, size - 1, l, r, delta);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int rectangleCount;
    cin >> rectangleCount;

    vector<Rectangle> rectangles(rectangleCount);
    Compressor compressor;
    for (auto &[x1, y1, x2, y2] : rectangles) {
        cin >> x1 >> y1 >> x2 >> y2;
        compressor.insert(y1);
        compressor.insert(y2);
    }
    compressor.insert(-1e9);
    compressor.insert(1e9);
    compressor.prepare();

    vector<Event> events;
    for (auto &[x1, y1, x2, y2] : rectangles) {
        int cy1 = compressor.compress(y1);
        int cy2 = compressor.compress(y2);
        events.push_back({ Event::BEGIN, x1, cy1, cy2 });
        events.push_back({ Event::END, x2, cy1, cy2 });
    }
    sort(events.begin(), events.end());

    long long res = 0;
    SegmentTree segmentTree(compressor);
    for (int i = 0; i < events.size(); i++) {
        auto &[type, x, cy1, cy2] = events[i];
        if (i)
            res += (x - events[i - 1].x) * ((long long)2e9 - segmentTree.getZeroCount());
        segmentTree.add(cy1, cy2 - 1, type == Event::BEGIN ? 1 : -1);
    }
    cout << res;
}