#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class SegmentTree {
    vector<int> t, tSet;
    int size;

    void build(int v, int vl, int vr, const string &s) {
        if (vl == vr) {
            t[v] = s[vl] - '0';
            tSet[v] = -1;
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, s);
        build(2 * v + 2, vm + 1, vr, s);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
        tSet[v] = -1;
    }

    void push(int v, int vl, int vr) {
        if (tSet[v] != -1) {
            if (tSet[v] == 0)
                t[v] = 0;
            else if (tSet[v] == 1)
                t[v] = vr - vl + 1;
            else
                t[v] = vr - vl + 1 - t[v];

            if (vl != vr) {
                if (tSet[v] != 2 || tSet[2 * v + 1] == -1)
                    tSet[2 * v + 1] = tSet[v];
                else
                    tSet[2 * v + 1] = 1 - tSet[2 * v + 1];
                
                if (tSet[v] != 2 || tSet[2 * v + 2] == -1)
                    tSet[2 * v + 2] = tSet[v];
                else
                    tSet[2 * v + 2] = 1 - tSet[2 * v + 2];
            }

            tSet[v] = -1;
        }
    }

    int query(int v, int vl, int vr, int l, int r) {
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
            tSet[v] = value;
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, value);
        modify(2 * v + 2, vm + 1, vr, l, r, value);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

public:
    SegmentTree(const string &s) {
        size = s.size();
        t.resize(4 * size);
        tSet.resize(4 * size);
        build(0, 0, size - 1, s);
    }

    int getSum(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void setValue(int l, int r, int value) {
        modify(0, 0, size - 1, l, r, value);
    }
};

void solve(int test) {
    int partCount;
    cin >> partCount;

    string s;
    for (int i = 0; i < partCount; i++) {
        int partReps;
        string part;
        cin >> partReps >> part;

        for (int j = 0; j < partReps; j++)
            s += part;
    }

    SegmentTree st(s);

    int queryCount;
    cin >> queryCount;

    cout << "Case " << test << ":\n";
    for (int i = 0, qi = 1; i < queryCount; i++) {
        char type;
        int l, r;
        cin >> type >> l >> r;

        if (type == 'F')
            st.setValue(l, r, 1);
        if (type == 'E')
            st.setValue(l, r, 0);
        if (type == 'I')
            st.setValue(l, r, 2);
        if (type == 'S')
            cout << "Q" << qi++ << ": " << st.getSum(l, r) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}