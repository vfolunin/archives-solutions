struct SegmentTree {
    vector<int> t;
    int size;

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

    int getMax(int r) {
        return query(0, 0, size - 1, 0, r);
    }

    void changeValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &a) {
        set<int> heights(a.begin(), a.end());
        unordered_map<int, int> indexOf;
        for (int height : heights)
            indexOf[height] = indexOf.size();
        
        vector<int> res(a.size());
        res[0] = 1;
        
        SegmentTree st(indexOf.size());
        st.changeValue(indexOf[a[0]], res[0]);
        
        for (int i = 1; i < a.size(); i++) {
            res[i] = st.getMax(indexOf[a[i]]) + 1;
            st.changeValue(indexOf[a[i]], res[i]);
        }
        
        return res;
    }
};