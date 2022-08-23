class Solution {
    int bfs(vector<vector<char>> &a, int startY, int startX) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> dist(h, vector<int>(w, 1e9));
        queue<pair<int, int>> q;
        
        dist[startY][startX] = 0;
        q.push({ startY, startX });
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
            
            if ((y != startY || x != startX) && (y == 0 || y == h - 1 || x == 0 || x == w - 1))
                return dist[y][x];
            
            static vector<int> dy = { -1, 0, 1, 0 };
            static vector<int> dx = { 0, 1, 0, -1 };
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] == '.' && dist[ty][tx] == 1e9) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return -1;
    }
    
public:
    int nearestExit(vector<vector<char>> &a, vector<int> &start) {
        return bfs(a, start[0], start[1]);
    }
};