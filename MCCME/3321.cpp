#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

struct SegmentTree {
    vector<int> t;
    int size;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            t[v] = a[vl];
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = gcd(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(vector<int> &a) : size(a.size()), t(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    int query(int v, int vl, int vr, int l, int r) const {
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return gcd(ql, qr);
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
        t[v] = gcd(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size) {}

    int getGcd(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void setValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
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
        char queryType;
        cin >> queryType;

        if (queryType == 's') {
            int l, r;
            cin >> l >> r;
            cout << segmentTree.getGcd(l - 1, r - 1) << " ";
        } else {
            int index, value;
            cin >> index >> value;
            segmentTree.setValue(index - 1, value);
        }
    }
}