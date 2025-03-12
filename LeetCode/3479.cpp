struct SegmentTree {
    struct Data {
        int minValue = 2e9, minIndex = 2e9;

        Data() {}

        Data(int value, int index) : minValue(value), minIndex(index) {}

        Data(Data &l, Data &r) {
            *this = l.minValue <= r.minValue ? l : r;
        }
    };

    int size;
    vector<Data> t;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            t[v] = Data(a[vl], vl);
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
            t[v] = Data(value, vl);
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

    int getMinIndex(int l, int r) {
        return query(0, 0, size - 1, l, r).minIndex;
    }

    void setValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int> &a, vector<int> &b) {
        vector<int> order(b.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int l, int r) {
            return b[l] < b[r];
        });

        SegmentTree segmentTree(order);
        sort(b.begin(), b.end());
        int res = 0;

        for (int value : a) {
            int index = segmentTree.getMinIndex(lower_bound(b.begin(), b.end(), value) - b.begin(), b.size() - 1);
            if (index < b.size())
                segmentTree.setValue(index, 2e9);
            else
                res++;
        }

        return res;
    }
};