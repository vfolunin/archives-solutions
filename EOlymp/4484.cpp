#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class SegmentTree {
    int size;
    vector<int> t;

    void build(int v, int vl, int vr, const string &a) {
        if (vl == vr) {
            t[v] = a[vl] == 'l';
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

    void modify(int v, int vl, int vr, int index, char value) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t[v] = value == 'l';
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index, value);
        modify(2 * v + 2, vm + 1, vr, index, value);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

public:
    SegmentTree(const string &a) : size(a.size()), t(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    int getSum(int l, int r) const {
        return query(0, 0, size - 1, l, r);
    }

    void setValue(int index, char value) {
        modify(0, 0, size - 1, index, value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    int queryCount;
    cin >> s >> queryCount;

    const long long MOD = 1e9 + 7;

    vector<long long> factorial(s.size() + 1);
    factorial[0] = 1;
    for (int i = 1; i < factorial.size(); i++)
        factorial[i] = factorial[i - 1] * i % MOD;

    SegmentTree segmentTree(s);

    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;

            int lCount = segmentTree.getSum(l - 1, r - 1);
            int dCount = r - l + 1 - lCount;

            cout << factorial[lCount] * factorial[dCount] % MOD << "\n";            
        } else {
            int index;
            char value;
            cin >> index >> value;

            segmentTree.setValue(index - 1, value);
        }
    }
}