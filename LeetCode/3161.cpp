struct SegmentTree {
    int size;
    vector<int> t, tObst;

    void build(int v, int vl, int vr) {
        if (vl == vr) {
            t[v] = size - vl;
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm);
        build(2 * v + 2, vm + 1, vr);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }

    void push(int v, int vl, int vr) {
        if (tObst[v] != 1e9) {
            t[v] = min(t[v], tObst[v] - vl);
            if (vl < vr) {
                tObst[2 * v + 1] = min(tObst[2 * v + 1], tObst[v]);
                tObst[2 * v + 2] = min(tObst[2 * v + 2], tObst[v]);
            }
            tObst[v] = 1e9;
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
        return max(ql, qr);
    }

    void modify(int v, int vl, int vr, int l, int r, int value) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            tObst[v] = min(tObst[v], value);
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, value);
        modify(2 * v + 2, vm + 1, vr, l, r, value);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size), tObst(4 * size, 1e9) {
        build(0, 0, size - 1);
    }

    int getMaxSpace(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void setObstacle(int l, int r, int index) {
        modify(0, 0, size - 1, l, r, index);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>> &queries) {
        set<int> obstacles = { 0 };
        SegmentTree segmentTree(1.5e5);
        vector<bool> res;

        for (vector<int> &query : queries) {
            if (query[0] == 1) {
                int index = query[1];
                int l = *prev(obstacles.upper_bound(index));
                int r = index - 1;

                obstacles.insert(index);
                segmentTree.setObstacle(l, r, index);
            } else {
                int index = query[1];
                int width = query[2];
                
                res.push_back(segmentTree.getMaxSpace(0, index - width) >= width);
            }
        }

        return res;
    }
};