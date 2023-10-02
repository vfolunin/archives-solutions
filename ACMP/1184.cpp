#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    struct Data {
        int value, index;

        Data() {}

        Data(int value, int index) : value(value), index(index) {}

        Data(Data &l, Data &r) {
            *this = l.value >= r.value ? l : r;
        }
    };

    int size;
    vector<Data> t;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            t[v] = Data(a[vl], vl);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    Data query(int v, int vl, int vr, int l, int r) {
        if (vr < l || r < vl)
            return Data(-2e9, -1);
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        Data ql = query(2 * v + 1, vl, vm, l, r);
        Data qr = query(2 * v + 2, vm + 1, vr, l, r);
        return Data(ql, qr);
    }

    SegmentTree(vector<int> &a) :
        size(a.size()), t(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    pair<int, int> getMaxIndex(int l, int r) {
        Data res = query(0, 0, size - 1, l, r);
        return { res.value, res.index };
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

    int opCount;
    cin >> opCount;

    for (int i = 0; i < opCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        auto [value, index] = segmentTree.getMaxIndex(l, r);
        cout << value << " " << index + 1 << "\n";
    }
}