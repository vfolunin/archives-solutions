#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    struct Data {
        int minH = 0, maxH = 0, h = 0;
        Data() {}
        Data(Data &l, Data &r) {
            minH = min(l.minH, r.minH);
            maxH = max(l.maxH, r.maxH);
        }
    };
    vector<Data> t;
    int size;

    void push(int v, int vl, int vr) {
        if (t[v].h) {
            t[v].minH = t[v].maxH = t[v].h;
            if (vl != vr) {
                t[v * 2 + 1].h = t[v].h;
                t[v * 2 + 2].h = t[v].h;
            }
            t[v].h = 0;
        }
    }

    int query(int v, int vl, int vr, int l, int r, int h) {
        push(v, vl, vr);

        if (vr < l || r < vl)
            return 0;

        if (l <= vl && vr <= r) {
            if (h < t[v].minH)
                return 0;

            if (t[v].maxH <= h)
                return vr - vl + 1;
        }

        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r, h);
        int qr = query(2 * v + 2, vm + 1, vr, l, r, h);
        return ql + qr;
    }

    void modify(int v, int vl, int vr, int l, int r, int h) {
        push(v, vl, vr);

        if (vr < l || r < vl)
            return;

        if (l <= vl && vr <= r) {
            if (h < t[v].minH)
                return;

            if (t[v].maxH <= h) {
                t[v].h = h;
                push(v, vl, vr);
                return;
            }
        }

        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, h);
        modify(2 * v + 2, vm + 1, vr, l, r, h);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size) {}

    int query(int l, int r, int h) {
        return query(0, 0, size - 1, l, r, h);
    }
    
    void modify(int l, int r, int h) {
        modify(0, 0, size - 1, l, r, h);
    }
};

void solve() {
    SegmentTree st(100000);

    int res = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r, h;
        cin >> l >> r >> h;

        res += st.query(l, r - 1, h);
        st.modify(l, r - 1, h);
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}