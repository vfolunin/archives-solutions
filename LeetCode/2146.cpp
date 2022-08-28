class Solution {   
    vector<vector<int>> bfs(vector<vector<int>> &a, int startY, int startX) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> dist(h, vector<int>(w, 1e9));
        dist[startY][startX] = 0;
        
        queue<pair<int, int>> q;
        q.push({ startY, startX });
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
                
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[y][x] && dist[ty][tx] == 1e9) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return dist;
    }
    
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &price, vector<int> &range, vector<int> &start, int k) {
        vector<vector<int>> dist = bfs(price, start[0], start[1]);
        
        vector<pair<int, int>> coords;
        for (int y = 0; y < price.size(); y++)
            for (int x = 0; x < price[0].size(); x++)
                if (range[0] <= price[y][x] && price[y][x] <= range[1] && dist[y][x] != 1e9)
                    coords.push_back({ y, x });
        
        sort(coords.begin(), coords.end(), [&](auto &a, auto &b) {
            auto &[ay, ax] = a;
            auto &[by, bx] = b;
            if (dist[ay][ax] != dist[by][bx])
                return dist[ay][ax] < dist[by][bx];
            if (price[ay][ax] != price[by][bx])
                return price[ay][ax] < price[by][bx];
            if (ay != by)
                return ay < by;
            return ax < bx;
        });
        
        vector<vector<int>> res;
        for (int i = 0; i < k && i < coords.size(); i++)
            res.push_back({ coords[i].first, coords[i].second });
        return res;
    }
};