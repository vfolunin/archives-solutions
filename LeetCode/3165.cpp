struct SegmentTree {
    struct Data {
        long long sum00 = 0, sum01 = 0, sum10 = 0, sum11 = 0, sum = 0;

        Data() {}

        Data(int value) : sum11(value), sum(max(value, 0)) {}

        Data(Data &l, Data &r) {
            sum00 = max({ l.sum00 + r.sum00, l.sum00 + r.sum10, l.sum01 + r.sum00 });
            sum01 = max({ l.sum00 + r.sum01, l.sum00 + r.sum11, l.sum01 + r.sum01 });
            sum10 = max({ l.sum10 + r.sum00, l.sum10 + r.sum10, l.sum11 + r.sum00 });
            sum11 = max({ l.sum10 + r.sum01, l.sum10 + r.sum11, l.sum11 + r.sum01 });
            sum = max({ sum00, sum01, sum10, sum11, 0LL });
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
        if (vr < l || r < vl)
            return {};
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        Data ql = query(2 * v + 1, vl, vm, l, r);
        Data qr = query(2 * v + 2, vm + 1, vr, l, r);
        return Data(ql, qr);
    }

    void modify(int v, int vl, int vr, int index, int value) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t[v] = Data(value);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index, value);
        modify(2 * v + 2, vm + 1, vr, index, value);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(vector<int> &a) : size(a.size()), t(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    long long getSum(int l, int r) {
        return query(0, 0, size - 1, l, r).sum;
    }

    void setValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

class Solution {
public:
    int maximumSumSubsequence(vector<int> &a, vector<vector<int>> &queries) {
        SegmentTree segmentTree(a);
        long long res = 0;
        const long long MOD = 1e9 + 7;

        for (int i = 0; i < queries.size(); i++) {
            segmentTree.setValue(queries[i][0], queries[i][1]);
            res = (res + segmentTree.getSum(0, a.size() - 1)) % MOD;
        }

        return res;
    }
};