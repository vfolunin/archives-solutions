class Solution {
    int bfs(vector<string> &a, int startY, int startX, int keyCount) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(1 << keyCount, 1e9)));
        queue<pair<pair<int, int>, int>> q;
        
        dist[startY][startX][0] = 0;
        q.push({ { startY, startX }, 0 });
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        while (!q.empty()) {
            auto [coords, mask] = q.front();
            auto [y, x] = coords;
            q.pop();
            
            if (mask == (1 << keyCount) - 1)
                return dist[y][x][mask];
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != '#' &&
                    (!isupper(a[ty][tx]) || (mask & (1 << (a[ty][tx] - 'A'))))) {
                    int tMask = mask;
                    if (islower(a[ty][tx]))
                        tMask |= 1 << (a[ty][tx] - 'a');
                        
                    if (dist[ty][tx][tMask] != 1e9)
                        continue;
                    
                    dist[ty][tx][tMask] = dist[y][x][mask] + 1;
                    q.push({ { ty, tx }, tMask });
                }
            }
        }
        
        return -1;
    }
    
public:
    int shortestPathAllKeys(vector<string> &a) {
        int startY, startX, keyCount = 0;
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x] == '@') {
                    startY = y;
                    startX = x;
                } else if (islower(a[y][x])) {
                    keyCount++;
                }
            }
        }
        
        return bfs(a, startY, startX, keyCount);
    }
};