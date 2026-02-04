#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    struct Data {
        vector<int> a;

        Data() {}

        Data(int value) : a(1, value) {}

        Data(Data &l, Data &r) {
            a.resize(l.a.size() + r.a.size());
            merge(l.a.begin(), l.a.end(), r.a.begin(), r.a.end(), a.begin());
        }
    };

    int size;
    vector<Data> t;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            t[v] = Data(a[vl]);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    int query(int v, int vl, int vr, int l, int r, int valueL, int valueR) {
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return upper_bound(t[v].a.begin(), t[v].a.end(), valueR) - lower_bound(t[v].a.begin(), t[v].a.end(), valueL);
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r, valueL, valueR);
        int qr = query(2 * v + 2, vm + 1, vr, l, r, valueL, valueR);
        return ql + qr;
    }

    SegmentTree(vector<int> &a) : size(a.size()), t(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    int getCount(int l, int r, int valueL, int valueR) {
        return query(0, 0, size - 1, l, r, valueL, valueR);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    SegmentTree segmentTree(a);
    for (int i = 0; i < queryCount; i++) {
        int l, r, valueL, valueR;
        cin >> l >> r >> valueL >> valueR;

        cout << segmentTree.getCount(l - 1, r - 1, valueL, valueR) << "\n";
    }
}