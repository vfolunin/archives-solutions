class Solution {
    int bfs01Sokoban(vector<vector<char>> &a, int sy, int sx, int by, int bx, int fy, int fx) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<vector<vector<int>>>> dist(h, vector<vector<vector<int>>>(
            w, vector<vector<int>>(h, vector<int>(w, 1e9))));
        deque<pair<pair<int, int>, pair<int, int>>> q;
        
        dist[sy][sx][by][bx] = 0;
        q.push_back({{ sy, sx }, { by, bx }});
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        while (!q.empty()) {
            auto [coords, bCoords] = q.front();
            q.pop_front();
            
            auto [y, x] = coords;
            auto [by, bx] = bCoords;
            
            if (by == fy && bx == fx)
                return dist[y][x][by][bx];
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != '#') {
                    if (ty == by && tx == bx) {
                        int tby = ty + dy[d];
                        int tbx = tx + dx[d];
                        
                        if (0 <= tby && tby < h && 0 <= tbx && tbx < w &&
                            a[tby][tbx] != '#' && dist[ty][tx][tby][tbx] > dist[y][x][by][bx] + 1) {
                            dist[ty][tx][tby][tbx] = dist[y][x][by][bx] + 1;
                            q.push_back({ { ty, tx }, { tby, tbx } });
                        }
                    } else if (dist[ty][tx][by][bx] > dist[y][x][by][bx]) {
                        dist[ty][tx][by][bx] = dist[y][x][by][bx];
                        q.push_front({ { ty, tx }, { by, bx } });
                    }
                }
            }
        }
        
        return -1;
    }
    
public:
    int minPushBox(vector<vector<char>> &a) {
        int sy, sx, by, bx, fy, fx;
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x] == 'S') {
                    sy = y;
                    sx = x;
                } else if (a[y][x] == 'B') {
                    by = y;
                    bx = x;
                } else if (a[y][x] == 'T') {
                    fy = y;
                    fx = x;
                }
            }
        }
        
        return bfs01Sokoban(a, sy, sx, by, bx, fy, fx);
    }
};