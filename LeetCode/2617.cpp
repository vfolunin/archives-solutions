struct SegmentTree {
    int size;
    vector<int> t;

    int query(int v, int vl, int vr, int l, int r) {
        if (vr < l || r < vl)
            return 1e9;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return min(ql, qr);
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
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size, 1e9) {}

    int getMin(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void setValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> res(h, vector<int>(w, 1e9));
        vector<SegmentTree> row(h, SegmentTree(w));
        vector<SegmentTree> col(w, SegmentTree(h));
        
        res[h - 1][w - 1] = 1;
        row[h - 1].setValue(w - 1, 1);
        col[w - 1].setValue(h - 1, 1);
        
        for (int y = h - 1; y >= 0; y--) {
            for (int x = w - 1; x >= 0; x--) {
                if (x < w - 1 && a[y][x]) {
                    int l = x + 1, r = min(x + a[y][x], w - 1);
                    res[y][x] = min(res[y][x], row[y].getMin(l, r) + 1);
                }
                if (y < h - 1 && a[y][x]) {
                    int l = y + 1, r = min(y + a[y][x], h - 1);
                    res[y][x] = min(res[y][x], col[x].getMin(l, r) + 1);
                }
                row[y].setValue(x, res[y][x]);
                col[x].setValue(y, res[y][x]);
            }
        }
        
        return res[0][0] != 1e9 ? res[0][0] : -1;
    }
};