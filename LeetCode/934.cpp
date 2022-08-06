class Solution {
    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    
    void dfs(vector<vector<int>> &a, int y, int x) {
        int h = a.size(), w = a[0].size();
        a[y][x] = 2;
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] == 1)
                dfs(a, ty, tx);
        }
    }
    
    int bfs(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> dist(h, vector<int>(w, 1e9));
        queue<pair<int, int>> q;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x] == 1) {
                    dist[y][x] = 0;
                    q.push({ y, x });
                }
            }
        }
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
            
            if (a[y][x] == 2)
                return dist[y][x];
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                if (0 <= ty && ty < h && 0 <= tx && tx < w && dist[ty][tx] == 1e9) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return 1e9;
    }
    
public:
    int shortestBridge(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size(), marked = 0;
        
        for (int y = 0; y < h && !marked; y++) {
            for (int x = 0; x < w && !marked; x++) {
                if (a[y][x]) {
                    dfs(a, y, x);
                    marked = 1;
                }
            }
        }
        
        return bfs(a) - 1;
    }
};