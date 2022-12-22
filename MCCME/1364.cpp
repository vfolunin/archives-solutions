#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    vector<long long> t, tAdd;
    int size;

    void push(int v, int vl, int vr) {
        if (tAdd[v]) {
            t[v] += (vr - vl + 1) * tAdd[v];
            if (vl < vr) {
                tAdd[2 * v + 1] += tAdd[v];
                tAdd[2 * v + 2] += tAdd[v];
            }
            tAdd[v] = 0;
        }
    }

    long long query(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return ql + qr;
    }

    void modify(int v, int vl, int vr, int l, int r, int value) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            tAdd[v] += value;
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, value);
        modify(2 * v + 2, vm + 1, vr, l, r, value);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    SegmentTree(int size) : size(size), t(4 * size), tAdd(4 * size) {}

    long long getSum(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void addValue(int l, int r, int value) {
        modify(0, 0, size - 1, l, r, value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;
    size++;

    SegmentTree segmentTree(size);

    for (int i = 0; i < queryCount; i++) {
        int queryType, l, r;
        cin >> queryType >> l >> r;
        r--;

        if (queryType == 1) {
            int value;
            cin >> value;

            segmentTree.addValue(l, r, value);
        } else {
            cout << segmentTree.getSum(l, r) << "\n";
        }
    }
}