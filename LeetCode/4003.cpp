class Solution {
public:
    long long minCost(int h, int w, vector<vector<int>> &penalty) {
        vector dist(h, vector(w, vector<long long>(2, 1e18)));
        set<tuple<long long, int, int, int>> q;

        dist[0][0][0] = 1;
        q.insert({ dist[0][0][0], 0, 0, 0 });

        while (!q.empty()) {
            auto [_, y, x, parity] = *q.begin();
            q.erase(q.begin());

            if (y == h - 1 && x == w - 1)
                return dist[y][x][parity];

            static vector<int> dy = { 0, -1, 1, 0, 0 };
            static vector<int> dx = { 0, 0, 0, -1, 1 };
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                if (ty < 0 || ty >= h || tx < 0 || tx >= w)
                    continue;

                int tParity = parity ^ 1;
                long long weight = 0;
                if (d)
                    weight += (ty + 1LL) * (tx + 1LL);
                if (!d || d % 2 != parity)
                    weight += penalty[y][x];

                if (dist[ty][tx][tParity] > dist[y][x][parity] + weight) {
                    q.erase({ dist[ty][tx][tParity], ty, tx, tParity });
                    dist[ty][tx][tParity] = dist[y][x][parity] + weight;
                    q.insert({ dist[ty][tx][tParity], ty, tx, tParity });
                }
            }
        }

        return 1e18;
    }
};