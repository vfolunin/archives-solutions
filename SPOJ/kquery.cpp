#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    int size;
    vector<vector<int>> t;

    void build(int v, int vl, int vr, const vector<int> &a) {
        if (vl == vr) {
            t[v].push_back(a[vl]);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        merge(t[2 * v + 1].begin(), t[2 * v + 1].end(), t[2 * v + 2].begin(), t[2 * v + 2].end(), back_inserter(t[v]));
    }

    int query(int v, int vl, int vr, int l, int r, int value) {
        if (r < vl || vr < l)
            return 0;
        if (l <= vl && vr <= r)
            return t[v].end() - upper_bound(t[v].begin(), t[v].end(), value);
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r, value);
        int qr = query(2 * v + 2, vm + 1, vr, l, r, value);
        return ql + qr;
    }

    SegmentTree(vector<int> &a) : size(a.size()), t(4 * size) {
        build(0, 0, size - 1, a);
    }

    int query(int l, int r, int value) {
        return query(0, 0, size - 1, l, r, value);
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
    for (int &value : a)
        cin >> value;

    int queryCount;
    cin >> queryCount;

    SegmentTree segmentTree(a);
    for (int i = 0; i < queryCount; i++) {
        int l, r, value;
        cin >> l >> r >> value;

        cout << segmentTree.query(l - 1, r - 1, value) << "\n";
    }
}