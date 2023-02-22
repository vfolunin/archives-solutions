struct SegmentTree {
    int size;
    vector<int> t, tSet;

    void push(int v, int vl, int vr) {
        if (tSet[v]) {
            t[v] = vr - vl + 1;
            if (vl < vr) {
                tSet[2 * v + 1] = 1;
                tSet[2 * v + 2] = 1;
            }
            tSet[v] = 0;
        }
    }

    int query(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return ql + qr;
    }

    void modify(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            tSet[v] = 1;
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r);
        modify(2 * v + 2, vm + 1, vr, l, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    SegmentTree(int size) : size(size), t(4 * size), tSet(4 * size) {}

    int getSum(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void paint(int l, int r) {
        modify(0, 0, size - 1, l, r);
    }
};

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>> &queries) {
        SegmentTree st(5e4);
        vector<int> res(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            res[i] = max(0, queries[i][1] - queries[i][0] - st.getSum(queries[i][0], queries[i][1] - 1));
            st.paint(queries[i][0], queries[i][1] - 1);
        }

        return res;
    }
};