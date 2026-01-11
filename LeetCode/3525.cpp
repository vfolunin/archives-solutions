struct SegmentTree {
    struct Data {
        int product = 1;
        vector<int> count;

        Data() {}

        Data(int value, int mod) : product(value % mod), count(mod) {
            count[value % mod] = 1;
        }

        Data(Data &l, Data &r, int mod) : product(l.product * r.product % mod), count(l.count) {
            for (int i = 0; i < count.size(); i++)
                count[l.product * i % mod] += r.count[i];
        }
    };

    int size, mod;
    vector<Data> t;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            t[v] = Data(a[vl], mod);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2], mod);
    }

    Data query(int v, int vl, int vr, int l, int r) {
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        if (r <= vm)
            return query(2 * v + 1, vl, vm, l, r);
        else if (vm < l)
            return query(2 * v + 2, vm + 1, vr, l, r);
        Data ql = query(2 * v + 1, vl, vm, l, r);
        Data qr = query(2 * v + 2, vm + 1, vr, l, r);
        return Data(ql, qr, mod);
    }

    void modify(int v, int vl, int vr, int index, int value) {
        if (vl == vr) {
            t[v] = Data(value, mod);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        if (index <= vm)
            modify(2 * v + 1, vl, vm, index, value);
        else
            modify(2 * v + 2, vm + 1, vr, index, value);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2], mod);
    }

    SegmentTree(vector<int> &a, int mod) : size(a.size()), mod(mod), t(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    int getCount(int l, int countIndex) {
        return query(0, 0, size - 1, l, size - 1).count[countIndex];
    }

    void setValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int> &a, int mod, vector<vector<int>> &queries) {
        SegmentTree segmentTree(a, mod);

        vector<int> res;
        for (vector<int> &query : queries) {
            int index = query[0], value = query[1], l = query[2], countIndex = query[3];
            segmentTree.setValue(index, value);
            res.push_back(segmentTree.getCount(l, countIndex));
        }
        return res;
    }
};