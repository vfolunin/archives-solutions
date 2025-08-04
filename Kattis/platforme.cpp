#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    struct Data {
        long long sum = 0;
        int set = -1e9;

        Data() {}

        Data(int value) : sum(value) {}

        Data(Data &l, Data &r) : sum(l.sum + r.sum) {}

        bool hasDelta() {
            return set != -1e9;
        }

        int getDelta() {
            return set;
        }

        void addDelta(int delta) {
            set = delta;
        }

        void applyDelta(int vl, int vr) {
            sum = (vr - vl + 1LL) * set;
            set = -1e9;
        }
    };

    int size;
    vector<Data> t;

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

    void modify(int v, int vl, int vr, int l, int r, int delta) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            t[v].addDelta(delta);
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, delta);
        modify(2 * v + 2, vm + 1, vr, l, r, delta);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size) {}

    long long getSum(int l, int r) {
        return query(0, 0, size - 1, l, r).sum;
    }

    void set(int l, int r, int value) {
        modify(0, 0, size - 1, l, r, value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    vector<vector<int>> queries(queryCount, vector<int>(3));
    for (vector<int> &query : queries)
        for (int &value : query)
            cin >> value;

    sort(queries.begin(), queries.end());

    SegmentTree segmentTree(1e4 + 1);
    long long res = 0;

    for (vector<int> &query : queries) {
        res += query[0] - segmentTree.getSum(query[1], query[1]);
        res += query[0] - segmentTree.getSum(query[2] - 1, query[2] - 1);
        segmentTree.set(query[1], query[2] - 1, query[0]);
    }

    cout << res;
}