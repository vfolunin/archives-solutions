class Solution {
public:
    int minMoves(vector<string> &a, int startE) {
        int h = a.size(), w = a[0].size();
        int startY, startX;
        map<pair<int, int>, int> lIndex;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x] == 'S') {
                    startY = y;
                    startX = x;
                } else if (a[y][x] == 'L') {
                    lIndex[{ y, x }] = lIndex.size();
                }
            }
        }

        vector dist(h, vector(w, vector(startE + 1, vector<int>(1 << lIndex.size(), 1e9))));
        queue<tuple<int, int, int, int>> q;

        dist[startY][startX][startE][0] = 0;
        q.push({ startY, startX, startE, 0 });

        while (!q.empty()) {
            auto [y, x, e, m] = q.front();
            q.pop();

            if (m == (1 << lIndex.size()) - 1)
                return dist[y][x][e][m];

            static vector<int> dy = { -1, 0, 1, 0 };
            static vector<int> dx = { 0, 1, 0, -1 };

            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (ty < 0 || ty >= h || tx < 0 || tx >= w || a[ty][tx] == 'X' || !e)
                    continue;
                
                int te = e - 1;
                if (a[ty][tx] == 'R')
                    te = startE;

                int tm = m;
                if (a[ty][tx] == 'L')
                    tm |= 1 << lIndex[{ ty, tx }];

                if (dist[ty][tx][te][tm] > dist[y][x][e][m] + 1) {
                    dist[ty][tx][te][tm] = dist[y][x][e][m] + 1;
                    q.push({ ty, tx, te, tm });
                }
            }
        }

        return -1;
    }
};