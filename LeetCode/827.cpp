struct DSU {
    vector<int> id, size;

    DSU(int n) {
        for (int v = 0; v < n; v++) {
            id.push_back(v);
            size.push_back(1);
        }
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
    int largestIsland(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        DSU dsu(h * w);
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (!a[y][x])
                    continue;
                
                for (int d = 0; d < dy.size(); d++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];
                    
                    if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx])
                        dsu.merge(y * w + x, ty * w + tx);
                }
            }
        }
        
        int res = *max_element(dsu.size.begin(), dsu.size.end());
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x])
                    continue;
                
                unordered_set<int> roots;
                
                for (int d = 0; d < dy.size(); d++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];
                    
                    if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx])
                        roots.insert(dsu.find(ty * w + tx));
                }
                
                int cur = 1;
                for (int root : roots)
                    cur += dsu.size[root];
                res = max(res, cur);
            }
        }
        
        return res;
    }
};