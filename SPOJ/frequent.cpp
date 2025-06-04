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
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }

    int query(int v, int vl, int vr, int l, int r) const {
        if (vr < l || r < vl)
            return -2e9;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return max(ql, qr);
    }

public:
    SegmentTree(const vector<int> &a) {
        size = a.size();
        t.resize(4 * size);
        build(0, 0, size - 1, a);
    }

    int getMax(int l, int r) const {
        return query(0, 0, size - 1, l, r);
    }
};

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int q;
    cin >> q;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> l(n);
    for (int i = 0; i < n; i++)
        l[i] = i && a[i - 1] == a[i] ? l[i - 1] + 1 : 1;

    vector<int> r(n);
    for (int i = n - 1; i >= 0; i--)
        r[i] = i < n - 1 && a[i] == a[i + 1] ? r[i + 1] + 1 : 1;

    SegmentTree st(l);

    for (int i = 0; i < q; i++) {
        int ql, qr;
        cin >> ql >> qr;
        ql--;
        qr--;

        int res = 0;
        res = max(res, min(r[ql], qr - ql + 1));
        res = max(res, min(l[qr], qr - ql + 1));
        if (ql + r[ql] <= qr)
            res = max(res, st.getMax(ql + r[ql], qr));
        cout << res << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}