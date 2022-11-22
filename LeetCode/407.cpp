class Solution {    
public:
    int trapRainWater(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> visited(h, vector<int>(w));
        set<pair<int, pair<int, int>>> q;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (y == 0 || y == h - 1 || x == 0 || x == w - 1) {
                    visited[y][x] = 1;
                    q.insert({ a[y][x], { y, x } });
                }
            }
        }
        
        int res = 0;
        
        while (!q.empty()) {
            auto [height, cell] = *q.begin();
            auto [y, x] = cell;
            q.erase(q.begin());
            
            static vector<int> dy = { -1, 0, 1, 0 };
            static vector<int> dx = { 0, 1, 0, -1 };
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < h && 0 <= tx && tx < w && !visited[ty][tx]) {
                    if (height > a[ty][tx])
                        res += height - a[ty][tx];
                    
                    visited[ty][tx] = 1;
                    q.insert({ max(height, a[ty][tx]), { ty, tx } });
                }
            }
        }
        
        return res;
    }
};