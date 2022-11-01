class Solution {
    int bfs(vector<vector<int>> &a, int startY, int startX, int finishY, int finishX) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> dist(h, vector<int>(w, 1e9));
        dist[startY][startX] = 0;
        
        queue<pair<int, int>> q;
        q.push({ startY, startX });
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
            
            if (y == finishY && x == finishX)
                return dist[y][x];
            
            static vector<int> dy = { -1, 0, 1, 0 };
            static vector<int> dx = { 0, 1, 0, -1 };
                
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[y][x] && dist[ty][tx] == 1e9) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return 1e9;
    }
    
public:
    int cutOffTree(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<pair<int, int>> order = { { 0, 0 } };
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (a[y][x] > 1)
                    order.push_back({ y, x });
        
        sort(order.begin() + 1, order.end(), [&](auto &pa, auto &pb) {
            return a[pa.first][pa.second] < a[pb.first][pb.second];
        });
        
        int res = 0;
        for (int i = 0; i + 1 < order.size(); i++) {
            int dist = bfs(a, order[i].first, order[i].second, order[i + 1].first, order[i + 1].second);
            if (dist != 1e9)
                res += dist;
            else
                return -1;
        }
        return res;
    }
};