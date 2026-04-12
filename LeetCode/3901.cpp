struct NaiveGcd {
    vector<int> values;
    int targetGcd;

    NaiveGcd(vector<int> &a, int targetGcd) : values(a), targetGcd(targetGcd) {
        for (int &value : values)
            value = value % targetGcd ? 0 : value / targetGcd;
    }

    bool setValue(int index, int value) {
        values[index] = value % targetGcd ? 0 : value / targetGcd;

        for (int i = 0; i < values.size(); i++) {
            int gcdValue = 0;
            for (int j = 0; j < values.size(); j++)
                if (i != j)
                    gcdValue = gcd(gcdValue, values[j]);

            if (gcdValue == 1)
                return 1;
        }

        return 0;
    }
};

struct SegmentTree {
    int size, targetGcd;
    vector<int> t;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            t[v] = a[vl] % targetGcd ? 0 : a[vl] / targetGcd;
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = gcd(t[2 * v + 1], t[2 * v + 2]);
    }

    void modify(int v, int vl, int vr, int index, int value) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t[v] = value % targetGcd ? 0 : value / targetGcd;
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index, value);
        modify(2 * v + 2, vm + 1, vr, index, value);
        t[v] = gcd(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(vector<int> &a, int targetGcd) : size(a.size()), targetGcd(targetGcd), t(4 * size) {
        build(0, 0, size - 1, a);
    }

    bool setValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
        return t[0] == 1;
    }
};

class Solution {
public:
    int countGoodSubseq(vector<int> &a, int targetGcd, vector<vector<int>> &queries) {
        int res = 0;

        if (a.size() < 20) {
            NaiveGcd naiveGcd(a, targetGcd);
            for (auto &query : queries)
                res += naiveGcd.setValue(query[0], query[1]);
        } else {
            SegmentTree segmentTree(a, targetGcd);
            for (auto &query : queries)
                res += segmentTree.setValue(query[0], query[1]);
        }

        return res;
    }
};