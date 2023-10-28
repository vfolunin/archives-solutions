const long long MOD = 1e9 + 7;

struct SegmentTree {
    struct Data {
        long long count = 1, sum = 0, squareSum = 0, add = 0;

        Data() {}

        Data(Data &l, Data &r) {
            count = l.count + r.count;
            sum = (l.sum + r.sum) % MOD;
            squareSum = (l.squareSum + r.squareSum) % MOD;
        }
    };
    int size;
    vector<Data> t;

    void build(int v, int vl, int vr) {
        if (vl == vr)
            return;
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm);
        build(2 * v + 2, vm + 1, vr);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    void push(int v, int vl, int vr) {
        if (!t[v].add)
            return;

        t[v].squareSum = (t[v].squareSum + 2 * t[v].sum * t[v].add % MOD + t[v].count * t[v].add * t[v].add % MOD) % MOD;
        t[v].sum = (t[v].sum + t[v].count * t[v].add) % MOD;

        if (vl != vr) {
            t[2 * v + 1].add += t[v].add;
            t[2 * v + 2].add += t[v].add;
        }
        t[v].add = 0;
    }

    Data query(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return Data();
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        Data ql = query(2 * v + 1, vl, vm, l, r);
        Data qr = query(2 * v + 2, vm + 1, vr, l, r);
        return Data(ql, qr);
    }

    void modify(int v, int vl, int vr, int l, int r, int value) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            t[v].add = (t[v].add + value) % MOD;
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, value);
        modify(2 * v + 2, vm + 1, vr, l, r, value);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size) {
        build(0, 0, size - 1);
    }

    long long add(int l, int r) {
        modify(0, 0, size - 1, l, r, 1);
        push(0, 0, size - 1);
        return t[0].squareSum;
    }
};

class Solution {
public:
    int sumCounts(vector<int> &a) {
        SegmentTree segmentTree(a.size());
        vector<int> lastPos(1e5 + 1, -1);
        long long res = 0;

        for (int i = 0; i < a.size(); i++) {
            res = (res + segmentTree.add(lastPos[a[i]] + 1, i)) % MOD;
            lastPos[a[i]] = i;
        }

        return res;
    }
};