#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    int size;
    vector<long long> t, tAdd;

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
        long long ql = query(2 * v + 1, vl, vm, l, r);
        long long qr = query(2 * v + 2, vm + 1, vr, l, r);
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

void solve() {
    int size, queryCount;
    cin >> size >> queryCount;

    SegmentTree segmentTree(size);

    for (int i = 0; i < queryCount; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        l--;
        r--;
        if (l > r)
            swap(l, r);

        if (type) {
            cout << segmentTree.getSum(l, r) << "\n";
        } else {
            int value;
            cin >> value;

            segmentTree.addValue(l, r, value);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}