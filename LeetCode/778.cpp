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

class Solution {
public:
    int swimInWater(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<pair<int, int>> cells;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                cells.push_back({ y, x });
        
        sort(cells.begin(), cells.end(), [&](auto &lhs, auto &rhs) {
            return a[lhs.first][lhs.second] < a[rhs.first][rhs.second];
        });
        
        vector<vector<int>> open(h, vector<int>(w));
        DSU dsu(h * w);
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        for (auto &[y, x] : cells) {
            open[y][x] = 1;
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                if (0 <= ty && ty < h && 0 <= tx && tx < w && open[ty][tx])
                    dsu.merge(y * w + x, ty * w + tx);
            }
                
            if (dsu.connected(0, h * w - 1))
                return a[y][x];
        }
        
        return -1;
    }
};