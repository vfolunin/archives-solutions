class Solution {
public:
    int minCost(vector<vector<int>> &a, int turnLimit) {
        vector dist(a.size(), vector(a[0].size(), vector(4, vector<int>(turnLimit + 1, 1e9))));
        set<tuple<int, int, int, int, int>> q;

        for (int d : { 1, 2 }) {
            dist[0][0][d][0] = a[0][0];
            q.insert({ dist[0][0][d][0], 0, 0, d, 0 });
        }

        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };

        while (!q.empty()) {
            auto [_, y, x, d, turns] = *q.begin();
            q.erase(q.begin());

            if (y == a.size() - 1 && x == a[0].size() - 1)
                return dist[y][x][d][turns];

            for (int td = 0; td < dy.size(); td++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                int tTurns = turns + (d != td);
                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && tTurns <= turnLimit &&
                    dist[ty][tx][td][tTurns] > dist[y][x][d][turns] + a[ty][tx]) {
                    q.erase({ dist[ty][tx][td][tTurns], ty, tx, td, tTurns });
                    dist[ty][tx][td][tTurns] = dist[y][x][d][turns] + a[ty][tx];
                    q.insert({ dist[ty][tx][td][tTurns], ty, tx, td, tTurns });
                }
            }
        }

        return -1;
    }
};