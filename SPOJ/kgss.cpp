#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class SegmentTree {
    vector<int> t1, t2;
    int size;

    void build(int v, int vl, int vr, const vector<int> &a) {
        if (vl == vr) {
            t1[v] = a[vl];
            t2[v] = -1e9;
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        vector<int> s = { t1[2 * v + 1], t1[2 * v + 2], t2[2 * v + 1], t2[2 * v + 2] };
        sort(s.begin(), s.end());
        t1[v] = s[3];
        t2[v] = s[2];
    }

    pair<int, int> query(int v, int vl, int vr, int l, int r) const {
        if (vr < l || r < vl)
            return { -1e9, -1e9 };
        if (l <= vl && vr <= r)
            return { t1[v], t2[v] };
        int vm = vl + (vr - vl) / 2;
        auto [l1, l2] = query(2 * v + 1, vl, vm, l, r);
        auto [r1, r2] = query(2 * v + 2, vm + 1, vr, l, r);
        vector<int> a = { l1, l2, r1, r2 };
        sort(a.begin(), a.end());
        return { a[3], a[2] };
    }

    void modify(int v, int vl, int vr, int index, int value) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t1[v] = value;
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index, value);
        modify(2 * v + 2, vm + 1, vr, index, value);
        vector<int> s = { t1[2 * v + 1], t1[2 * v + 2], t2[2 * v + 1], t2[2 * v + 2] };
        sort(s.begin(), s.end());
        t1[v] = s[3];
        t2[v] = s[2];
    }

public:
    SegmentTree(const vector<int> &a) {
        size = a.size();
        t1.resize(4 * size);
        t2.resize(4 * size);
        build(0, 0, size - 1, a);
    }

    int getSum(int l, int r) const {
        auto [a, b] = query(0, 0, size - 1, l, r);
        return a + b;
    }

    void changeValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    SegmentTree st(a);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        char type;
        cin >> type;

        if (type == 'Q') {
            int l, r;
            cin >> l >> r;
            cout << st.getSum(l - 1, r - 1) << "\n";
        } else {
            int index, value;
            cin >> index >> value;
            st.changeValue(index - 1, value);
        }
    }
}