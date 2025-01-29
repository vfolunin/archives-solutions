#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
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

    int query(int v, int vl, int vr, int l, int r, int k) const {
        if (r < vl || vr < l)
            return 0;
        if (l <= vl && vr <= r)
            return t[v].end() - upper_bound(t[v].begin(), t[v].end(), k);
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r, k);
        int qr = query(2 * v + 2, vm + 1, vr, l, r, k);
        return ql + qr;
    }

    SegmentTree(const vector<int> &a) {
        size = a.size();
        t.resize(4 * size);
        build(0, 0, size - 1, a);
    }

    int query(int l, int r, int k) const {
        return query(0, 0, size - 1, l, r, k);
    }
};

int query(SegmentTree &st, int from, int k, int size) {
    int l = from + k - 2, r = size;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (st.query(from, m, m) >= k)
            r = m;
        else
            l = m;
    }
    return r < size ? r + 1 : 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int pointCount, serverCount;
    cin >> pointCount >> serverCount;

    vector<int> serverOf(pointCount);
    unordered_map<int, vector<int>> pointsOf;

    for (int i = 0; i < pointCount; i++) {
        cin >> serverOf[i];
        pointsOf[serverOf[i]].push_back(i);
    }

    for (auto &[_, pointsOf] : pointsOf)
        pointsOf.push_back(1e9);

    vector<int> nextPoint(pointCount);
    for (int i = 0; i < pointCount; i++)
        nextPoint[i] = *upper_bound(pointsOf[serverOf[i]].begin(), pointsOf[serverOf[i]].end(), i);

    SegmentTree segmentTree(nextPoint);

    int queryCount;
    cin >> queryCount;

    int res = 0;
    for (int i = 0; i < queryCount; i++) {
        int x, y;
        cin >> x >> y;

        int from = (x + res) % pointCount;
        int k = (y + res) % serverCount + 1;

        res = query(segmentTree, from, k, pointCount);

        cout << res << "\n";
    }
}