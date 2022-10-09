class Solution {
    int bfs(vector<vector<int>> &a, int limit) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(limit + 1, 1e9)));
        queue<pair<pair<int, int>, int>> q;
        
        dist[0][0][limit] = 0;
        q.push({ { 0, 0 }, limit });
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        while (!q.empty()) {
            auto [coords, k] = q.front();
            auto [y, x] = coords;
            q.pop();
            
            if (y == h - 1 && x == w - 1)
                return dist[y][x][k];
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < h && 0 <= tx && tx < w) {
                    int tk = k - a[ty][tx];
                    
                    if (tk < 0 || dist[ty][tx][tk] != 1e9)
                        continue;
                    
                    dist[ty][tx][tk] = dist[y][x][k] + 1;
                    q.push({ { ty, tx }, tk });
                }
            }
        }
        
        return -1;
    }
    
public:
    int shortestPath(vector<vector<int>> &a, int limit) {
        return bfs(a, limit);
    }
};