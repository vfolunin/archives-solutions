class Solution {
    vector<vector<int>> bfs() {
        vector<vector<int>> dist(310, vector<int>(310, 1e9));
        queue<pair<int, int>> q;
        
        dist[5][5] = 0;
        q.push({ 5, 5 });
        
        vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
        vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
                
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < dist.size() && 0 <= tx && tx < dist[0].size() && dist[ty][tx] == 1e9) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return dist;
    }

public:
    int minKnightMoves(int y, int x) {
        static vector<vector<int>> dist = bfs();
        return dist[abs(y) + 5][abs(x) + 5];
    }
};