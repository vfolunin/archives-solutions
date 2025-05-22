class Solution {
public:
    int minMoves(vector<string> &a) {            
        vector<vector<pair<int, int>>> teleports(26);
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                if (isupper(a[y][x]))
                    teleports[a[y][x] - 'A'].push_back({ y, x });

        vector<int> teleportUsed(26);

        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
        deque<pair<int, int>> q;
        
        dist[0][0] = 0;
        q.push_back({ 0, 0 });
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop_front();

            if (isupper(a[y][x]) && !teleportUsed[a[y][x] - 'A']) {
                teleportUsed[a[y][x] - 'A'] = 1;
                for (auto &[ty, tx] : teleports[a[y][x] - 'A']) {
                    if (dist[ty][tx] > dist[y][x]) {
                        dist[ty][tx] = dist[y][x];
                        q.push_front({ ty, tx });
                    }
                }
            }
                
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#' && dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push_back({ ty, tx });
                }
            }
        }
        
        return dist.back().back() != 1e9 ? dist.back().back() : -1;
    }
};