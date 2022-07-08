class Solution {
    void dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited) {
        visited[y][x] = 1;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() &&
                a[y][x] <= a[ty][tx] && !visited[ty][tx])
                dfs(a, ty, tx, visited);
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> visitedL(h, vector<int>(w));
        for (int y = 0; y < h; y++)
            if (!visitedL[y][0])
                dfs(a, y, 0, visitedL);
        for (int x = 0; x < w; x++)
            if (!visitedL[0][x])
                dfs(a, 0, x, visitedL);
        
        vector<vector<int>> visitedR(h, vector<int>(w));
        for (int y = 0; y < h; y++)
            if (!visitedR[y][w - 1])
                dfs(a, y, w - 1, visitedR);
        for (int x = 0; x < w; x++)
            if (!visitedR[h - 1][x])
                dfs(a, h - 1, x, visitedR);
        
        vector<vector<int>> res;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (visitedL[y][x] && visitedR[y][x])
                    res.push_back({ y, x });
        return res;
    }
};