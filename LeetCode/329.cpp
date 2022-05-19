class Solution {
    void dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &dist) {
        dist[y][x] = 1;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[y][x] < a[ty][tx]) {
                if (!dist[ty][tx])
                    dfs(a, ty, tx, dist);
                
                dist[y][x] = max(dist[y][x], 1 + dist[ty][tx]);
            }
        }
    }
    
public:
    int longestIncreasingPath(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> dist(h, vector<int>(w));        
        int res = 0;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (!dist[y][x])
                    dfs(a, y, x, dist);
                res = max(res, dist[y][x]);
            }
        }
        
        return res;
    }
};