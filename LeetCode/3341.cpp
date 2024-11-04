class Solution {
public:
    int minTimeToReach(vector<vector<int>> &a) {
        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 2e9));
        set<tuple<int, int, int>> q;

        dist[0][0] = 0;
        q.insert({ dist[0][0], 0, 0 });

        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };

        while (!q.empty()) {
            auto [_, y, x] = *q.begin();
            q.erase(q.begin());

            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && dist[ty][tx] > max(dist[y][x], a[ty][tx]) + 1) {
                    q.erase({ dist[ty][tx], ty, tx });
                    dist[ty][tx] = max(dist[y][x], a[ty][tx]) + 1;
                    q.insert({ dist[ty][tx], ty, tx });
                }
            }
        }

        return dist.back().back();
    }
};