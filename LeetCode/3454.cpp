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
    int x1, x2, y;

    bool operator < (const Event &that) const {
        if (y != that.y)
            return y < that.y;
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

class Solution {
    double calcSquareUnion(vector<vector<int>> &squares, double areaLimit) {
        Compressor compressor;
        for (vector<int> &square : squares) {
            compressor.insert(square[0]);
            compressor.insert(square[0] + square[2]);
        }
        compressor.insert(0);
        compressor.insert(2e9);
        compressor.prepare();

        vector<Event> events;
        for (vector<int> &square : squares) {
            int cx1 = compressor.compress(square[0]);
            int cx2 = compressor.compress(square[0] + square[2]);
            events.push_back({ Event::BEGIN, cx1, cx2, square[1] });
            events.push_back({ Event::END, cx1, cx2, square[1] + square[2] });
        }
        sort(events.begin(), events.end());

        double area = 0;
        SegmentTree segmentTree(compressor);
        for (int i = 0; i < events.size(); i++) {
            auto &[type, cx1, cx2, y] = events[i];
            if (i) {
                double dx = 2e9 - segmentTree.getZeroCount();
                double dy = y - events[i - 1].y;
                if (areaLimit && area + dx * dy >= areaLimit)
                    return events[i - 1].y + (areaLimit - area) / dx;
                area += dx * dy;
            }
            segmentTree.add(cx1, cx2 - 1, type == Event::BEGIN ? 1 : -1);
        }
        return area;
    }

public:
    double separateSquares(vector<vector<int>> &squares) {
        double areaLimit = calcSquareUnion(squares, 0) / 2;
        return calcSquareUnion(squares, areaLimit);
    }
};