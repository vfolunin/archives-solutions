#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    struct Data {
        int sum, maxPrefixSum, maxSuffixSum, maxSum;

        Data() {}

        Data(int value) : sum(value), maxPrefixSum(value), maxSuffixSum(value), maxSum(value) {}

        Data(Data &l, Data &r) {
            sum = l.sum + r.sum;
            maxPrefixSum = max(l.maxPrefixSum, l.sum + r.maxPrefixSum);
            maxSuffixSum = max(l.maxSuffixSum + r.sum, r.maxSuffixSum);
            maxSum = max({ l.maxSum, r.maxSum, l.maxSuffixSum + r.maxPrefixSum });
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

    Data query(int v, int vl, int vr, int l, int r) {
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        if (r <= vm)
            return query(2 * v + 1, vl, vm, l, r);
        if (vm < l)
            return query(2 * v + 2, vm + 1, vr, l, r);
        Data ql = query(2 * v + 1, vl, vm, l, r);
        Data qr = query(2 * v + 2, vm + 1, vr, l, r);
        return Data(ql, qr);
    }

    void modify(int v, int vl, int vr, int index, int value) {
        if (vl == vr) {
            t[v] = Data(value);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        if (index <= vm)
            modify(2 * v + 1, vl, vm, index, value);
        else
            modify(2 * v + 2, vm + 1, vr, index, value);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(vector<int> &a) : size(a.size()), t(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    int getMaxSum(int l, int r) {
        return query(0, 0, size - 1, l, r).maxSum;
    }

    void setValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    SegmentTree segmentTree(a);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type) {
            int l, r;
            cin >> l >> r;

            cout << segmentTree.getMaxSum(l - 1, r - 1) << "\n";
        } else {
            int index, value;
            cin >> index >> value;

            segmentTree.setValue(index - 1, value);
        }
    }
}