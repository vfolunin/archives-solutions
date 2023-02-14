class Solution {
    void dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited, vector<pair<int, int>> &cc) {
        visited[y][x] = 1;
        cc.push_back({ y, x });
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] && !visited[ty][tx])
                dfs(a, ty, tx, visited, cc);
        }
    }

    void normalize(vector<pair<int, int>> &cc) {
        int minY = 1e9, minX = 1e9;
        for (auto &[y, x] : cc) {
            minY = min(minY, y);
            minX = min(minX, x);
        }
        for (auto &[y, x] : cc) {
            y -= minY;
            x -= minX;
        }
    }

public:
    int numDistinctIslands(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        set<vector<pair<int, int>>> ccs;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x] && !visited[y][x]) {
                    vector<pair<int, int>> cc;
                    dfs(a, y, x, visited, cc);
                    normalize(cc);
                    ccs.insert(cc);
                }
            }
        }
        
        return ccs.size();
    }
};