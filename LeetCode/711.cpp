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

    vector<pair<int, int>> flip(vector<pair<int, int>> cc) {
        int maxX = 0;
        for (auto &[y, x] : cc) 
            maxX = max(maxX, x);
        for (auto &[y, x] : cc)
            x = maxX - x;
        sort(cc.begin(), cc.end());
        return cc;
    }

    vector<pair<int, int>> rotate(const vector<pair<int, int>> &cc) {
        int maxY = 0, maxX = 0;
        for (auto &[y, x] : cc) {
            maxY = max(maxY, y);
            maxX = max(maxX, x);
        }
        vector<pair<int, int>> res;
        for (auto &[y, x] : cc)
            res.push_back({ maxX - x, y });
        sort(res.begin(), res.end());
        return res;
    }

    vector<pair<int, int>> normalize(vector<pair<int, int>> cc) {
        int minY = 1e9, minX = 1e9;
        for (auto &[y, x] : cc) {
            minY = min(minY, y);
            minX = min(minX, x);
        }
        for (auto &[y, x] : cc) {
            y -= minY;
            x -= minX;
        }

        vector<pair<int, int>> res = cc;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                cc = rotate(cc);
                res = min(res, cc);
            }
            cc = flip(cc);
        }
        return res;
    }

public:
    int numDistinctIslands2(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        set<vector<pair<int, int>>> ccs;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x] && !visited[y][x]) {
                    vector<pair<int, int>> cc;
                    dfs(a, y, x, visited, cc);
                    ccs.insert(normalize(cc));
                }
            }
        }
        
        return ccs.size();
    }
};