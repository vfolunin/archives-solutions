class Solution {
    vector<vector<int>> bfs(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> dist(h, vector<int>(w, 2e9));
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
            
            static vector<int> dy = { -1, 0, 1, 0 };
            static vector<int> dx = { 0, 1, 0, -1 };
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != 2 &&
                    dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return dist;
    }
    
    bool can(vector<vector<int>> &a, vector<vector<int>> &fireTime, int time) {
        if (time >= fireTime[0][0])
            return 0;
        
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> dist(h, vector<int>(w, 2e9));
        queue<pair<int, int>> q;
        
        dist[0][0] = time;
        q.push({ 0, 0 });
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
            
            if (y == h - 1 && x == w - 1)
                return 1;
            
            static vector<int> dy = { -1, 0, 1, 0 };
            static vector<int> dx = { 0, 1, 0, -1 };
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != 2 &&
                    dist[ty][tx] > dist[y][x] + 1 && (fireTime[ty][tx] > dist[y][x] + 1 ||
                    ty == h - 1 && tx == w - 1 && fireTime[ty][tx] == dist[y][x] + 1)) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return 0;
    }
    
public:
    int maximumMinutes(vector<vector<int>> &a) {
        vector<vector<int>> fireTime = bfs(a);
        
        int l = -1, r = 1e9 + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, fireTime, m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};