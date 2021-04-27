#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

struct SegmentTree {
    vector<int> t;
    int size;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            t[v] = 1 << a[vl];
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = t[2 * v + 1] | t[2 * v + 2];
    }

    int query(int v, int vl, int vr, int l, int r) {
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return ql | qr;
    }

public:
    SegmentTree(vector<int> &a) {
        size = a.size();
        t.resize(4 * size);
        build(0, 0, size - 1, a);
    }

    int getUnique(int l, int r) {
        return ones(query(0, 0, size - 1, l, r));
    }
};

bool solve() {
    int aSize;
    if (!(cin >> aSize))
        return 0;

    vector<int> a(aSize);
    for (int &x : a)
        cin >> x;

    SegmentTree st(a);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        cout << st.getUnique(l - 1, r - 1) << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}