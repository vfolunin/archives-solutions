class Solution {
    int bfs(vector<vector<char>> &a) {
        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
        queue<pair<int, int>> q;

        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x] == '*') {
                    dist[y][x] = 0;
                    q.push({ y, x });
                }
            }
        }
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            if (a[y][x] == '#')
                return dist[y][x];

            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[y][x] != 'X' && dist[ty][tx] == 1e9) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return -1;
    }

public:
    int getFood(vector<vector<char>> &a) {
        return bfs(a);
    }
};