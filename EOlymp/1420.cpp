#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <array>
using namespace std;

void bfs(int sy1, int sx1, int sy2, int sx2, int fy1, int fx1, int fy2, int fx2) {
    vector dist(8, vector(8, vector(8, vector<int>(8, 1e9))));
    vector from(8, vector(8, vector(8, vector<array<int, 4>>(8, { -1, -1, -1, -1 }))));
    queue<array<int, 4>> q;

    dist[sy1][sx1][sy2][sx2] = 0;
    q.push({ sy1, sx1, sy2, sx2 });

    while (!q.empty()) {
        auto [y1, x1, y2, x2] = q.front();
        q.pop();

        if (y1 == fy1 && x1 == fx1 && y2 == fy2 && x2 == fx2) {
            vector<array<int, 4>> path;
            while (y1 != -1) {
                path.push_back({ y1, x1, y2, x2 });
                auto &[py1, px1, py2, px2] = from[y1][x1][y2][x2];
                y1 = py1;
                x1 = px1;
                y2 = py2;
                x2 = px2;
            }
            reverse(path.begin(), path.end());
            for (int i = 1; i < path.size(); i++) {
                if (path[i - 1][0] != path[i][0])
                    cout << "1 " << (char)(path[i][1] + 'a') << (char)(path[i][0] + '1') << "\n";
                else
                    cout << "2 " << (char)(path[i][3] + 'a') << (char)(path[i][2] + '1') << "\n";
            }
            return;
        }

        static vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
        static vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

        for (int d = 0; d < dy.size(); d++) {
            int ty1 = y1 + dy[d];
            int tx1 = x1 + dx[d];

            if (0 <= ty1 && ty1 < 8 && 0 <= tx1 && tx1 < 8 && (ty1 != y2 || tx1 != x2) &&
                dist[ty1][tx1][y2][x2] > dist[y1][x1][y2][x2] + 1) {
                dist[ty1][tx1][y2][x2] = dist[y1][x1][y2][x2] + 1;
                from[ty1][tx1][y2][x2] = {y1, x1, y2, x2};
                q.push({ ty1, tx1, y2, x2 });
            }

            int ty2 = y2 + dy[d];
            int tx2 = x2 + dx[d];

            if (0 <= ty2 && ty2 < 8 && 0 <= tx2 && tx2 < 8 && (y1 != ty2 || x1 != tx2) &&
                dist[y1][x1][ty2][tx2] > dist[y1][x1][y2][x2] + 1) {
                dist[y1][x1][ty2][tx2] = dist[y1][x1][y2][x2] + 1;
                from[y1][x1][ty2][tx2] = { y1, x1, y2, x2 };
                q.push({ y1, x1, ty2, tx2 });
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char sy1, sx1, sy2, sx2, fy1, fx1, fy2, fx2;
    cin >> sx1 >> sy1 >> sx2 >> sy2 >> fx1 >> fy1 >> fx2 >> fy2;

    bfs(sy1 - '1', sx1 - 'a', sy2 - '1', sx2 - 'a',
        fy1 - '1', fx1 - 'a', fy2 - '1', fx2 - 'a');
}