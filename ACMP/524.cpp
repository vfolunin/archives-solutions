#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void bfs(int startY, int startX, int finishY, int finishX) {
    vector<vector<int>> dist(8, vector<int>(8, 1e9));
    vector<vector<pair<int, int>>> from(8, vector<pair<int, int>>(8, { -1, -1 }));
    queue<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push({ startY, startX });

    vector<int> dy = { -1, -1, 1, 1 };
    vector<int> dx = { -1, 1, 1, -1 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (y == finishY && x == finishX) {
            vector<pair<int, int>> path;
            while (y != startY || x != startX) {
                path.push_back({ y, x });
                auto &[py, px] = from[y][x];
                y = py;
                x = px;
            }
            reverse(path.begin(), path.end());

            cout << dist[finishY][finishX] << "\n";
            for (int i = 0; i + 1 < path.size(); i++)
                cout << path[i].first + 1 << " " << path[i].second + 1 << "\n";
            return;
        }

        for (int d = 0; d < dy.size(); d++) {
            for (int step = 1; step < 8; step++) {
                int ty = y + dy[d] * step;
                int tx = x + dx[d] * step;

                if (0 <= ty && ty < 8 && 0 <= tx && tx < 8 && dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    from[ty][tx] = { y, x };
                    q.push({ ty, tx });
                }
            }
        }
    }

    cout << 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int startY, startX, finishY, finishX;
    cin >> startY >> startX >> finishY >> finishX;

    bfs(startY - 1, startX - 1, finishY - 1, finishX - 1);
}