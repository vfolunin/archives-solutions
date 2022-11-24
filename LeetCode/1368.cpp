class Solution {
    int bfs01(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> dist(h, vector<int>(w, 1e9));
        deque<pair<int, int>> q;

        dist[0][0] = 0;
        q.push_back({ 0, 0 });
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop_front();
            
            static vector<int> dy = { 0, 0, 1, -1 };
            static vector<int> dx = { 1, -1, 0, 0 };
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[y][x] - 1 != d && dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push_back({ ty, tx });
                } else if (0 <= ty && ty < h && 0 <= tx && tx < w && a[y][x] - 1 == d && dist[ty][tx] > dist[y][x]) {
                    dist[ty][tx] = dist[y][x];
                    q.push_front({ ty, tx });
                }
            }
        }
        
        return dist[h - 1][w - 1];
    }
    
public:
    int minCost(vector<vector<int>> &a) {
        return bfs01(a);
    }
};