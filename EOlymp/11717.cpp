#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    struct Data {
        int minValue = (1 << 31) - 1;
        int set = -1e9;

        Data() {}

        Data(int value) : minValue(value) {}

        Data(Data &l, Data &r) : minValue(min(l.minValue, r.minValue)) {}

        bool hasDelta() {
            return set != -1e9;
        }

        int getDelta() {
            return set;
        }

        void addDelta(int delta) {
            set = delta;
        }

        void applyDelta(int vl, int vr) {
            minValue = set;
            set = -1e9;
        }
    };

    int size;
    vector<Data> t;

    void push(int v, int vl, int vr) {
        if (t[v].hasDelta()) {
            if (vl != vr) {
                int vm = vl + (vr - vl) / 2;
                t[2 * v + 1].addDelta(t[v].getDelta());
                t[2 * v + 2].addDelta(t[v].getDelta());
            }
            t[v].applyDelta(vl, vr);
        }
    }

    Data query(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return {};
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        Data ql = query(2 * v + 1, vl, vm, l, r);
        Data qr = query(2 * v + 2, vm + 1, vr, l, r);
        return Data(ql, qr);
    }

    void modify(int v, int vl, int vr, int l, int r, int delta) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            t[v].addDelta(delta);
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, delta);
        modify(2 * v + 2, vm + 1, vr, l, r, delta);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size) {}

    int getMinValue(int l, int r) {
        return query(0, 0, size - 1, l, r).minValue;
    }

    void set(int l, int r, int value) {
        modify(0, 0, size - 1, l, r, value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    SegmentTree segmentTree(size);

    for (int i = 0; i < queryCount; i++) {
        int type, l, r;
        cin >> type >> l >> r;

        if (!type) {
            int value;
            cin >> value;

            segmentTree.set(l, r, value);
        } else {
            cout << segmentTree.getMinValue(l, r) << "\n";
        }
    }
}