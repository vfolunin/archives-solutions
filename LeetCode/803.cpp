struct DSU {
    vector<int> id, size;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        size.assign(n, 1);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (size[ri] < size[rj]) {
            id[ri] = rj;
            size[rj] += size[ri];
        } else {
            id[rj] = ri;
            size[ri] += size[rj];
        }
    }
};

class Solution {    
public:
    vector<int> hitBricks(vector<vector<int>> &initialA, vector<vector<int>> &hits) {
        int h = initialA.size(), w = initialA[0].size();
        
        vector<vector<int>> a = initialA;
        for (vector<int> &hit : hits)
            a[hit[0]][hit[1]] = 0;
        
        DSU dsu(h * w + 1);
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (!a[y][x])
                    continue;
                
                if (!y)
                    dsu.merge(x, h * w);

                for (int d = 0; d < dy.size(); d++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];
                    if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx])
                        dsu.merge(y * w + x, ty * w + tx);
                }
            }
        }
        
        vector<int> res(hits.size());
        int stableCount = dsu.size[dsu.find(h * w)] - 1;
        
        for (int i = hits.size() - 1; i >= 0; i--) {
            int y = hits[i][0], x = hits[i][1];
            if (!initialA[y][x])
                continue;
            
            a[y][x] = 1;
            
            if (!y)
                dsu.merge(x, h * w);
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx])
                    dsu.merge(y * w + x, ty * w + tx);
            }
            
            int prevStableCount = dsu.size[dsu.find(h * w)] - 1;
            res[i] = prevStableCount - stableCount - dsu.connected(y * w + x, h * w);
            stableCount = prevStableCount;
        }
        
        return res;
    }
};