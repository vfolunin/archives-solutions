#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    int size;
    vector<int> t;

    int query(int v, int vl, int vr, int l, int r) {
        if (vr < l || r < vl)
            return 1e9;
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

    SegmentTree(int size) : size(size), t(4 * size, 1e9) {}

    int getMin(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void setValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

void solve() {
    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(3));
    for (vector<int> &row : a)
        for (int &value : row)
            cin >> value;

    sort(a.begin(), a.end());
    SegmentTree segmentTree(size + 1);

    int res = 0;
    for (vector<int> &row : a) {
        res += segmentTree.getMin(0, row[1]) > row[2];
        segmentTree.setValue(row[1], row[2]);
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