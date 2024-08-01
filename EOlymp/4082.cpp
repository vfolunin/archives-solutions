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
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    int query(int v, int vl, int vr, int l, int r) const {
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return ql + qr;
    }

    void modify(int v, int vl, int vr, int index, int value) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t[v] = value;
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index, value);
        modify(2 * v + 2, vm + 1, vr, index, value);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

public:
    SegmentTree(const vector<int> &a) {
        size = a.size();
        t.resize(4 * size);
        build(0, 0, size - 1, a);
    }

    int getSum(int l, int r) const {
        return query(0, 0, size - 1, l, r);
    }

    void changeValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

bool solve() {
    int n, queryCount;
    if (!(cin >> n >> queryCount))
        return 0;

    vector<int> minuses(n), zeros(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        minuses[i] = x < 0;
        zeros[i] = x == 0;
    }

    SegmentTree minusesST(minuses), zerosST(zeros);

    for (int i = 0; i < queryCount; i++) {
        char type;
        cin >> type;

        if (type == 'C') {
            int index, value;
            cin >> index >> value;
            minusesST.changeValue(index - 1, value < 0);
            zerosST.changeValue(index - 1, value == 0);
        } else {
            int l, r;
            cin >> l >> r;
            if (zerosST.getSum(l - 1, r - 1))
                cout << '0';
            else if (minusesST.getSum(l - 1, r - 1) % 2)
                cout << '-';
            else
                cout << '+';
        }
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}