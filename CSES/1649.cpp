#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class SegmentTree {
    vector<int> t;
    int size;

    void build(int v, int vl, int vr, const vector<int> &a) {
        if (vl == vr) {
            t[v] = a[vl];
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }

    int query(int v, int vl, int vr, int l, int r) const {
        if (vr < l || r < vl)
            return 2e9;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return min(ql, qr);
    }

    void modify(int v, int vl, int vr, int index, int value) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t[v] = value;
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index, value);
        modify(2 * v + 2, vm + 1, vr, index, value);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }

public:
    SegmentTree(const vector<int> &a) {
        size = a.size();
        t.resize(4 * size);
        build(0, 0, size - 1, a);
    }

    int getMin(int l, int r) const {
        return query(0, 0, size - 1, l, r);
    }

    void changeValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    SegmentTree segmentTree(a);

    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int index, val;
            cin >> index >> val;
            index--;
            segmentTree.changeValue(index, val);
            a[index] = val;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << segmentTree.getMin(l, r) << "\n";
        }
    }
}