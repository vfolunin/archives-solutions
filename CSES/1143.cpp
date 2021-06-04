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

    int query(int v, int vl, int vr, int value) const {
        if (t[v] < value)
            return -1;
        if (vl == vr)
            return vl;
        int vm = vl + (vr - vl) / 2;
        if (t[2 * v + 1] >= value)
            return query(2 * v + 1, vl, vm, value);
        else
            return query(2 * v + 2, vm + 1, vr, value);
    }

    void modify(int v, int vl, int vr, int index, int delta) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t[v] += delta;
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index, delta);
        modify(2 * v + 2, vm + 1, vr, index, delta);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }

public:
    SegmentTree(const vector<int> &a) {
        size = a.size();
        t.resize(4 * size);
        build(0, 0, size - 1, a);
    }

    int get(int value) {
        int index = query(0, 0, size - 1, value);
        if (index != -1)
            modify(0, 0, size - 1, index, -value);
        return index;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    SegmentTree segmentTree(a);

    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;
        cout << segmentTree.get(value) + 1 << " ";
    }
}