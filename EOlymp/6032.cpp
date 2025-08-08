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
            while (y != -1 && x != -1) {
                path.push_back({ y, x });
                auto [py, px] = from[y][x];
                y = py;
                x = px;
            }
            reverse(path.begin(), path.end());

            cout << dist[finishY][finishX];
            for (auto &[y, x] : path)
                cout << " " << (char)(x + 'A') << " " << (char)(y + '1');
            cout << "\n";
            return;
        }

        for (int d = 0; d < dy.size(); d++) {
            for (int step = 1; step < 8; step++) {
                int ty = y + dy[d] * step;
                int tx = x + dx[d] * step;

                if (ty < 0 || ty >= dist.size() || tx < 0 || tx >= dist.size())
                    break;

                if (dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    from[ty][tx] = { y, x };
                    q.push({ ty, tx });
                }
            }
        }
    }

    cout << "Impossible\n";
}

void solve() {
    char startX, startY, finishX, finishY;
    cin >> startX >> startY >> finishX >> finishY;

    bfs(startY - '1', startX - 'A', finishY - '1', finishX - 'A');
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}