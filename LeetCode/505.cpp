class Solution {
    int dijkstra(vector<vector<int>> &a, int startY, int startX, int finishY, int finishX) {
        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
        set<pair<int, pair<int, int>>> q;
        
        dist[startY][startX] = 0;
        q.insert({ 0, { startY, startX } });
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        while (!q.empty()) {
            auto [y, x] = q.begin()->second;
            q.erase(q.begin());
                
            for (int d = 0; d < dy.size(); d++) {
                int step = 0;
                while (1) {
                    int ty = y + dy[d] * (step + 1);
                    int tx = x + dx[d] * (step + 1);

                    if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && !a[ty][tx])
                        step++;
                    else
                        break;
                }

                int ty = y + dy[d] * step;
                int tx = x + dx[d] * step;
            
                if (dist[ty][tx] > dist[y][x] + step) {
                    q.erase({ dist[ty][tx], { ty, tx } });
                    dist[ty][tx] = dist[y][x] + step;
                    q.insert({ dist[ty][tx], { ty, tx } });
                }
            }
        }
        
        return dist[finishY][finishX];
    }

public:
    int shortestDistance(vector<vector<int>> &a, vector<int> &start, vector<int> &finish) {
        int res = dijkstra(a, start[0], start[1], finish[0], finish[1]);
        return res != 1e9 ? res : -1;
    }
};