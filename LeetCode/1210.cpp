class Solution {
    int bfs(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(2, 1e9)));
        queue<pair<pair<int, int>, int>> q;
        
        dist[0][0][0] = 0;
        q.push({ { 0, 0 }, 0 });
        
        while (!q.empty()) {
            auto [coord, vertical] = q.front();
            auto [y, x] = coord;
            q.pop();
            
            if (y == h - 1 && x == w - 2 && !vertical)
                return dist[y][x][vertical];

            if (!vertical) {
                if (x + 2 < w && !a[y][x + 2] && dist[y][x + 1][0] == 1e9) {
                    dist[y][x + 1][0] = dist[y][x][0] + 1;
                    q.push({ { y, x + 1 }, 0 });
                }
                if (y + 1 < h && !a[y + 1][x] && !a[y + 1][x + 1] && dist[y + 1][x][0] == 1e9) {
                    dist[y + 1][x][0] = dist[y][x][0] + 1;
                    q.push({ { y + 1, x }, 0 });
                }
                if (y + 1 < h && !a[y + 1][x] && !a[y + 1][x + 1] && dist[y][x][1] == 1e9) {
                    dist[y][x][1] = dist[y][x][0] + 1;
                    q.push({ { y, x }, 1 });
                }
            } else {
                if (x + 1 < w && !a[y][x + 1] && !a[y + 1][x + 1] && dist[y][x + 1][1] == 1e9) {
                    dist[y][x + 1][1] = dist[y][x][1] + 1;
                    q.push({ { y, x + 1 }, 1 });
                }
                if (y + 2 < h && !a[y + 2][x] && dist[y + 1][x][1] == 1e9) {
                    dist[y + 1][x][1] = dist[y][x][1] + 1;
                    q.push({ { y + 1, x }, 1 });
                }
                if (x + 1 < w && !a[y][x + 1] && !a[y + 1][x + 1] && dist[y][x][0] == 1e9) {
                    dist[y][x][0] = dist[y][x][1] + 1;
                    q.push({ { y, x }, 0 });
                }
            }
        }
        
        return -1;
    }
    
public:
    int minimumMoves(vector<vector<int>> &a) {
        return bfs(a);
    }
};