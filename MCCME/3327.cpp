#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    int size;
    vector<long long> t, tAdd;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            t[v] = a[vl];
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    void push(int v, int vl, int vr) {
        if (tAdd[v]) {
            t[v] += (vr - vl + 1) * tAdd[v];
            if (vl < vr) {
                tAdd[2 * v + 1] += tAdd[v];
                tAdd[2 * v + 2] += tAdd[v];
            }
            tAdd[v] = 0;
        }
    }

    long long query(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        long long ql = query(2 * v + 1, vl, vm, l, r);
        long long qr = query(2 * v + 2, vm + 1, vr, l, r);
        return ql + qr;
    }

    void modify(int v, int vl, int vr, int l, int r, int value) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            tAdd[v] += value;
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, value);
        modify(2 * v + 2, vm + 1, vr, l, r, value);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    SegmentTree(vector<int> &a) :
        size(a.size()), t(4 * a.size()), tAdd(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    long long getSum(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void addValue(int l, int r, int value) {
        modify(0, 0, size - 1, l, r, value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    SegmentTree segmentTree(a);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        char type;
        cin >> type;

        if (type == 'g') {
            int index;
            cin >> index;
            cout << segmentTree.getSum(index - 1, index - 1) << "\n";
        } else {
            int l, r, value;
            cin >> l >> r >> value;
            segmentTree.addValue(l - 1, r - 1, value);
        }
    }
}