#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    struct Data {
        int sum = 0, minPrefixSum = 0;

        Data() {}

        Data(int value) : sum(value), minPrefixSum(value) {}

        Data(Data &l, Data &r) {
            sum = l.sum + r.sum;
            minPrefixSum = min(l.minPrefixSum, l.sum + r.minPrefixSum);
        }
    };

    int size;
    vector<Data> t;

    void build(int v, int vl, int vr, string &s) {
        if (vl == vr) {
            t[v] = Data(s[vl] == '(' ? 1 : -1);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, s);
        build(2 * v + 2, vm + 1, vr, s);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    Data query(int v, int vl, int vr, int l, int r) {
        if (vr < l || r < vl)
            return {};
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        Data ql = query(2 * v + 1, vl, vm, l, r);
        Data qr = query(2 * v + 2, vm + 1, vr, l, r);
        return Data(ql, qr);
    }

    void modify(int v, int vl, int vr, int index) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t[v] = Data(-t[v].sum);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index);
        modify(2 * v + 2, vm + 1, vr, index);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(string &s) : size(s.size()), t(4 * s.size()) {
        build(0, 0, size - 1, s);
    }

    bool isCorrect(int index) {
        modify(0, 0, size - 1, index);
        return !t[0].sum && !t[0].minPrefixSum;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    SegmentTree segmentTree(s);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int index;
        cin >> index;

        cout << (segmentTree.isCorrect(index) ? "+\n" : "-\n");
    }
}