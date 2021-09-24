#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    vector<int> t, tInv;
    int size;

    void push(int v, int vl, int vr) {
        if (tInv[v]) {
            t[v] = vr - vl + 1 - t[v];
            if (vl != vr) {
                tInv[2 * v + 1] ^= 1;
                tInv[2 * v + 2] ^= 1;
            }
            tInv[v] = 0;
        }
    }

    int query(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return ql + qr;
    }

    void modify(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            tInv[v] = 1;
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r);
        modify(2 * v + 2, vm + 1, vr, l, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    SegmentTree(int size) : size(size), t(4 * size), tInv(4 * size) {}

    int query(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void modify(int l, int r) {
        modify(0, 0, size - 1, l, r);
    }
};


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    SegmentTree st(size);

    for (int i = 0; i < queryCount; i++) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 0)
            st.modify(l - 1, r - 1);
        else
            cout << st.query(l - 1, r - 1) << "\n";
    }
}