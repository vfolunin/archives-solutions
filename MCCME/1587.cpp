#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    struct Data {
        int maxValue = 0;

        Data() {}

        Data(int value) : maxValue(value) {}

        Data(Data &l, Data &r) : maxValue(max(l.maxValue, r.maxValue)) {}
    };

    int size;
    vector<Data> t;

    Data query(int v, int vl, int vr, int l, int r) {
        if (vr < l || r < vl)
            return {};
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        Data ql = query(2 * v + 1, vl, vm, l, r);
        Data qr = query(2 * v + 2, vm + 1, vr, l, r);
        return Data(ql, qr);
    }

    void modify(int v, int vl, int vr, int index, int value) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t[v] = Data(value);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index, value);
        modify(2 * v + 2, vm + 1, vr, index, value);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size) {}

    int getMaxValue(int l, int r) {
        return query(0, 0, size - 1, l, r).maxValue;
    }

    void setValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int size;
    cin >> size;

    SegmentTree down(1e4 + 1), up(1e4 + 1);

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        down.setValue(value, up.getMaxValue(value + 1, 1e4) + 1);
        up.setValue(value, down.getMaxValue(0, value - 1) + 1);
    }

    cout << size - max(down.getMaxValue(0, 1e4), up.getMaxValue(0, 1e4));
}