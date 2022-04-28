class Solution {
    struct DSU {
        vector<int> id;

        DSU(int n) {
            for (int v = 0; v < n; v++)
                id.push_back(v);
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
            if (rand() % 2)
                id[ri] = rj;
            else
                id[rj] = ri;
        }
    };
    
    struct Edge {
        int a, b, w;
        
        bool operator < (const Edge &that) const {
            return w < that.w;
        }
    };
    
public:
    int minimumEffortPath(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<Edge> edges;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (y)
                    edges.push_back({ (y - 1) * w + x, y * w + x, abs(a[y - 1][x] - a[y][x]) });
                if (x)
                    edges.push_back({ y * w + x - 1, y * w + x, abs(a[y][x - 1] - a[y][x]) });
            }
        }
        
        sort(edges.begin(), edges.end());
        DSU dsu(h * w);
        
        for (auto &[a, b, weight] : edges) {
            dsu.merge(a, b);
            if (dsu.connected(0, h * w - 1))
                return weight;
        }
        return 0;
    }
};