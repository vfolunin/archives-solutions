#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    int size;
    vector<int> t, tAdd;

    void push(int v, int vl, int vr) {
        if (tAdd[v]) {
            t[v] += tAdd[v];
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
            return -2e9;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return max(ql, qr);
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
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size), tAdd(4 * size) {}

    int getMax(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void addValue(int l, int r, int value) {
        modify(0, 0, size - 1, l, r, value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int stationCount, seatCount, queryCount;
    cin >> stationCount >> seatCount >> queryCount;

    SegmentTree segmentTree(stationCount);

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        r--;

        if (segmentTree.getMax(l, r) < seatCount) {
            cout << "Yes\n";
            segmentTree.addValue(l, r, 1);
        } else {
            cout << "No\n";
        }
    }
}