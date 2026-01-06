struct Compressor {
    unordered_map<int, int> compressed;
    vector<int> decompressed;

    void insert(int value) {
        decompressed.push_back(value);
    }

    void prepare() {
        sort(decompressed.begin(), decompressed.end());
        decompressed.erase(unique(decompressed.begin(), decompressed.end()), decompressed.end());
        for (int i = 0; i < decompressed.size(); i++) 
            compressed[decompressed[i]] = i;
    }

    int size() {
        return compressed.size();
    }

    int compress(int value) {
        return compressed[value];
    }

    int decompress(int value) {
        return decompressed[value];
    }
};

struct SegmentTree {
    int size;
    vector<vector<int>> t;

    void build(int v, int vl, int vr, vector<vector<int>> &a) {
        if (vl == vr) {
            t[v] = a[vl];
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        merge(t[2 * v + 1].begin(), t[2 * v + 1].end(), t[2 * v + 2].begin(), t[2 * v + 2].end(), back_inserter(t[v]));
    }

    int query(int v, int vl, int vr, int l, int r, int value) {
        if (l <= vl && vr <= r) {
            auto it = upper_bound(t[v].begin(), t[v].end(), value);
            return it != t[v].end() ? *it : 1e9;
        }
        int vm = vl + (vr - vl) / 2;
        if (r <= vm)
            return query(2 * v + 1, vl, vm, l, r, value);
        if (vm < l)
            return query(2 * v + 2, vm + 1, vr, l, r, value);
        int ql = query(2 * v + 1, vl, vm, l, r, value);
        int qr = query(2 * v + 2, vm + 1, vr, l, r, value);
        return min(ql, qr);
    }

    SegmentTree(vector<vector<int>> &a) {
        size = a.size();
        t.resize(4 * size);
        build(0, 0, size - 1, a);
    }

    int query(int l, int r, int value) {
        return query(0, 0, size - 1, l, r, value);
    }
};

class Solution {
public:
    long long maxRectangleArea(vector<int> &x, vector<int> &y) {
        Compressor compressorX, compressorY;
        for (int i = 0; i < x.size(); i++) {
            compressorX.insert(x[i]);
            compressorY.insert(y[i]);
        }
        compressorX.prepare();
        compressorY.prepare();

        vector<vector<int>> cys(compressorX.size());
        vector<set<int>> cxs(compressorY.size());
        for (int i = 0; i < x.size(); i++) {
            int cx = compressorX.compress(x[i]);
            int cy = compressorY.compress(y[i]);
            cys[cx].push_back(cy);
            cxs[cy].insert(cx);
        }
        for (vector<int> &cys : cys)
            sort(cys.begin(), cys.end());

        SegmentTree segmentTree(cys);
        long long res = -1;
        for (int cy1 = 0; cy1 < compressorY.size(); cy1++) {
            vector<int> curCxs(cxs[cy1].begin(), cxs[cy1].end());
            for (int i = 0; i + 1 < curCxs.size(); i++) {
                int cx1 = curCxs[i];
                int cx2 = curCxs[i + 1];
                int cy2 = segmentTree.query(cx1, cx2, cy1);
                if (cy2 != 1e9 && cxs[cy2].contains(cx1) && cxs[cy2].contains(cx2)) {
                    long long dx = compressorX.decompress(cx2) - compressorX.decompress(cx1);
                    long long dy = compressorY.decompress(cy2) - compressorY.decompress(cy1);
                    res = max(res, dx * dy);
                }
            }
        }
        return res;
    }
};