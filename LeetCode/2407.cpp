struct SegmentTree {
    int size;
    vector<int> t;

    int query(int v, int vl, int vr, int l, int r) const {
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return max(ql, qr);
    }

    void modify(int v, int vl, int vr, int index, int value) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t[v] = value;
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index, value);
        modify(2 * v + 2, vm + 1, vr, index, value);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size) {}

    int getMax(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void changeValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int> &a, int diff) {
        SegmentTree st(1e5 + 1);
        
        for (int value : a)
            st.changeValue(value, st.getMax(max(value - diff, 0), value - 1) + 1);
        
        return st.getMax(0, 1e5);
    }
};