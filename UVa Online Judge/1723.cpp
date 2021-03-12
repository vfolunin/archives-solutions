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

    void push(int v, int vl, int vr) {
        if (tSet[v]) {
            t[v] = vr - vl + 1;
            if (vl != vr) {
                tSet[2 * v + 1] = tSet[v];
                tSet[2 * v + 2] = tSet[v];
            }
            tSet[v] = 0;
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

    void modify(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            tSet[v] = 1;
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r);
        modify(2 * v + 2, vm + 1, vr, l, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

public:
    SegmentTree(int size) : size(size) {
        t.resize(4 * size);
        tSet.resize(4 * size);
    }

    int sum(int l, int r) {
        return l <= r ? query(0, 0, size - 1, l, r) : 0;
    }

    void set(int l, int r) {
        if (l <= r)
            modify(0, 0, size - 1, l, r);
    }
};

struct Interval {
    int l, r, k;

    bool operator < (const Interval &that) const {
        return r < that.r;
    }
};

void solve(int test) {
    int intervalCount;
    cin >> intervalCount;

    vector<Interval> intervals(intervalCount);
    for (auto &[l, r, k] : intervals)
        cin >> l >> r >> k;
    sort(intervals.begin(), intervals.end());

    SegmentTree st(50001);
    for (auto &[l, r, k] : intervals) {

        int fromL = l - 1, fromR = r + 2;
        while (fromL + 1 < fromR) {
            int fromM = fromL + (fromR - fromL) / 2;
            int sum1 = st.sum(l, fromM - 1);
            int sum2 = r - fromM + 1;
            if (sum1 + sum2 < k)
                fromR = fromM;
            else
                fromL = fromM;
        }
        st.set(fromL, r);

    }

    if (test)
        cout << "\n";
    cout << st.sum(0, 50000) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}