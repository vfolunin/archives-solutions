#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    struct Data {
        int maxIndex, maxValue;

        Data() {}

        Data(int index, int value) : maxIndex(index), maxValue(value) {}

        Data(Data &l, Data &r) {
            if (l.maxValue >= r.maxValue)
                *this = l;
            else
                *this = r;
        }
    };

    vector<Data> t;
    int size;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            t[v] = Data(vl, a[vl]);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    Data query(int v, int vl, int vr, int l, int r) const {
        if (vr < l || r < vl)
            return Data(-1, -1e9);
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        Data ql = query(2 * v + 1, vl, vm, l, r);
        Data qr = query(2 * v + 2, vm + 1, vr, l, r);
        return Data(ql, qr);
    }

    SegmentTree(vector<int> &a) : size(a.size()), t(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    int getMaxIndex(int l, int r) {
        return query(0, 0, size - 1, l, r).maxIndex;
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

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;

        cout << segmentTree.getMaxIndex(l - 1, r - 1) + 1 << " ";
    }
}