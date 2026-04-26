struct SegmentTree {
    struct Data {
        long long maxValue = 0;

        Data() {}

        Data(long long value) : maxValue(value) {}

        Data(Data &l, Data &r) : maxValue(max(l.maxValue, r.maxValue)) {}
    };

    int size;
    vector<Data> t;

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

    void modify(int v, int vl, int vr, int index, long long value) {
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

    SegmentTree(int size) : size(size), t(4 * size) {}

    long long getMaxValue(int l, int r) {
        return query(0, 0, size - 1, l, r).maxValue;
    }

    void setValue(int index, long long value) {
        modify(0, 0, size - 1, index, value);
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int> &a, int dist) {
        int size = 1e5 + 1;
        SegmentTree stUp(size), stDown(size);
        vector<long long> up, down;

        for (int i = 0; i < a.size(); i++) {
            if (i >= dist) {
                stUp.setValue(a[i - dist], up[i - dist]);
                stDown.setValue(a[i - dist], down[i - dist]);
            }

            up.push_back(a[i] + max(stDown.getMaxValue(0, a[i] - 1), 0LL));
            down.push_back(a[i] + max(stUp.getMaxValue(a[i] + 1, size - 1), 0LL));
        }

        return max(*max_element(up.begin(), up.end()), *max_element(down.begin(), down.end()));
    }
};