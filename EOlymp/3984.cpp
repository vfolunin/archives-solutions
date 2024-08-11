#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    struct Data {
        long long squareSum = 0;
        long long sum = 0;
        int set = -1e9;
        int add = 0;

        Data() {}

        Data(int value) : squareSum(value * value), sum(value) {}

        Data(Data &l, Data &r) : squareSum(l.squareSum + r.squareSum), sum(l.sum + r.sum) {}

        bool hasDelta() {
            return set != -1e9 || add;
        }

        pair<int, int> getDelta() {
            return { set, add };
        }

        void addDelta(pair<int, int> delta) {
            if (delta.first != -1e9) {
                set = delta.first;
                add = 0;
            }
            add += delta.second;
        }

        void applyDelta(int vl, int vr) {
            if (set != -1e9) {
                squareSum = (vr - vl + 1LL) * set * set;
                sum = (vr - vl + 1LL) * set;
                set = -1e9;
            }
            if (add) {
                squareSum += 2 * add * sum + (vr - vl + 1LL) * add * add;
                sum += (vr - vl + 1LL) * add;
                add = 0;
            }
        }
    };

    int size;
    vector<Data> t;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            t[v] = Data(a[vl]);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    void push(int v, int vl, int vr) {
        if (t[v].hasDelta()) {
            if (vl != vr) {
                int vm = vl + (vr - vl) / 2;
                t[2 * v + 1].addDelta(t[v].getDelta());
                t[2 * v + 2].addDelta(t[v].getDelta());
            }
            t[v].applyDelta(vl, vr);
        }
    }

    Data query(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return {};
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        Data ql = query(2 * v + 1, vl, vm, l, r);
        Data qr = query(2 * v + 2, vm + 1, vr, l, r);
        return Data(ql, qr);
    }

    void modify(int v, int vl, int vr, int l, int r, int add, int set) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            t[v].addDelta({ add, set });
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, add, set);
        modify(2 * v + 2, vm + 1, vr, l, r, add, set);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(vector<int> &a) : size(a.size()), t(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    long long getSquareSum(int l, int r) {
        return query(0, 0, size - 1, l, r).squareSum;
    }

    void set(int l, int r, int value) {
        modify(0, 0, size - 1, l, r, value, 0);
    }

    void add(int l, int r, int value) {
        modify(0, 0, size - 1, l, r, -1e9, value);
    }
};

void solve(int test) {
    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    SegmentTree segmentTree(a);
    cout << "Case " << test << ":\n";

    for (int i = 0; i < queryCount; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        l--;
        r--;

        if (type == 0) {
            int value;
            cin >> value;

            segmentTree.set(l, r, value);
        } else if (type == 1) {
            int value;
            cin >> value;

            segmentTree.add(l, r, value);
        } else {
            cout << segmentTree.getSquareSum(l, r) << "\n";
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}