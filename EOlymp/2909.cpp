#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    struct Data {
        vector<int> count;
        int add = 0;

        Data() : count(3) {}

        Data(int) : count(3) {
            count[0] = 1;
        }

        Data(Data &l, Data &r) : count(3) {
            for (int i = 0; i < count.size(); i++)
                count[i] = l.count[i] + r.count[i];
        }

        void addDelta(int delta) {
            add = (add + delta) % count.size();
        }

        int getDelta() {
            return add;
        }

        void applyDelta() {
            rotate(count.begin(), count.begin() + add, count.end());
            add = 0;
        }
    };

    int size;
    vector<Data> t;

    void build(int v, int vl, int vr) {
        if (vl == vr) {
            t[v] = Data(1);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm);
        build(2 * v + 2, vm + 1, vr);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    void push(int v, int vl, int vr) {
        if (t[v].getDelta()) {
            if (vl != vr) {
                int vm = vl + (vr - vl) / 2;
                t[2 * v + 1].addDelta(t[v].getDelta());
                t[2 * v + 2].addDelta(t[v].getDelta());
            }
            t[v].applyDelta();
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

    void modify(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            t[v].addDelta(1);
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r);
        modify(2 * v + 2, vm + 1, vr, l, r);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size) {
        build(0, 0, size - 1);
    }

    int getDivisibleCount(int l, int r) {
        return query(0, 0, size - 1, l, r).count[0];
    }

    void addOne(int l, int r) {
        modify(0, 0, size - 1, l, r);
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

        if (type)
            cout << segmentTree.getDivisibleCount(l, r) << "\n";
        else
            segmentTree.addOne(l, r);
    }
}