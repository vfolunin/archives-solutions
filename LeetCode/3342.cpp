class Solution {
public:
    int minTimeToReach(vector<vector<int>> &a) {
        vector dist(a.size(), vector(a[0].size(), vector<int>(2, 2e9)));
        set<tuple<int, int, int, int>> q;

        dist[0][0][0] = 0;
        q.insert({ dist[0][0][0], 0, 0, 0 });

        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };

        while (!q.empty()) {
            auto [_, y, x, p] = *q.begin();
            q.erase(q.begin());

            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                int tp = !p;

                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() &&
                    dist[ty][tx][tp] > max(dist[y][x][p], a[ty][tx]) + 1 + p) {
                    q.erase({ dist[ty][tx][tp], ty, tx, tp });
                    dist[ty][tx][tp] = max(dist[y][x][p], a[ty][tx]) + 1 + p;
                    q.insert({ dist[ty][tx][tp], ty, tx, tp });
                }
            }
        }

        return min(dist.back().back()[0], dist.back().back()[1]);
    }
};