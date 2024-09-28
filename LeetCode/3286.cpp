class Solution {
    int dijkstra(vector<vector<int>> &a) {
        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
        set<pair<int, pair<int, int>>> q;

        dist[0][0] = a[0][0];
        q.insert({ dist[0][0], { 0, 0 } });

        while (!q.empty()) {
            auto [y, x] = q.begin()->second;
            q.erase(q.begin());

            static vector<int> dy = { -1, 0, 1, 0 };
            static vector<int> dx = { 0, 1, 0, -1 };

            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && dist[ty][tx] > dist[y][x] + a[ty][tx]) {
                    q.erase({ dist[ty][tx], { ty, tx } });
                    dist[ty][tx] = dist[y][x] + a[ty][tx];
                    q.insert({ dist[ty][tx], { ty, tx } });
                }
            }
        }

        return dist.back().back();
    }
public:
    bool findSafeWalk(vector<vector<int>> &a, int health) {
        return dijkstra(a) < health;
    }
};