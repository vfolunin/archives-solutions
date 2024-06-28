struct SegmentTree {
    int size;
    vector<int> t;

    int query(int v, int vl, int vr, int l, int r) {
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return ql + qr;
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
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    SegmentTree(int size) : size(size), t(4 * size) {}

    int getSum(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void setValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int> &a, vector<vector<int>> &queries) {
        SegmentTree segmentTree(a.size());
        for (int i = 1; i + 1 < a.size(); i++)
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
                segmentTree.setValue(i, 1);
        
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 1) {
                int l = queries[i][1] + 1;
                int r = queries[i][2] - 1;
                res.push_back(l <= r ? segmentTree.getSum(l, r) : 0);
            } else {
                int index = queries[i][1];
                int value = queries[i][2];
                a[index] = value;
                for (int j = index - 1; j <= index + 1; j++)
                    segmentTree.setValue(j, 0 < j && j + 1 < a.size() && a[j - 1] < a[j] && a[j] > a[j + 1]);
            }
        }
        return res;
    }
};