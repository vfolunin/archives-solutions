#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

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

        Data(int value) : minValue(value), minCount(1) {}

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

    int size;
    vector<Data> t;

    void build(int v, int vl, int vr) {
        if (vl == vr)
            return;
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

    SegmentTree(int size) : size(size), t(4 * size) {
        build(0, 0, size - 1);
    }

    int getNonzeroCount() {
        return t[0].minValue ? 0 : size - t[0].minCount;
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

    vector<Event> events;
    for (int i = 0; i < rectangleCount; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1 += 1e6;
        y2 += 1e6;

        events.push_back({ Event::BEGIN, x1, y1, y2 });
        events.push_back({ Event::END, x2, y1, y2 });
    }
    sort(events.begin(), events.end());

    long long res = 0;
    SegmentTree segmentTree(2e6 + 1);
    for (int i = 0; i < events.size(); i++) {
        auto &[type, x, y1, y2] = events[i];
        if (i)
            res += 1LL * (x - events[i - 1].x) * segmentTree.getNonzeroCount();
        segmentTree.add(y1, y2 - 1, type == Event::BEGIN ? 1 : -1);
    }
    cout << res;
}