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

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (y == finishY && x == finishX) {
            vector<pair<int, int>> path;
            while (y != -1) {
                path.push_back({ y, x });
                auto &[py, px] = from[y][x];
                y = py;
                x = px;
            }
            reverse(path.begin(), path.end());
            for (auto &[y, x] : path)
                cout << (char)(x + 'a') << (char)(y + '1') << "\n";
            return;
        }

        static vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
        static vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < 8 && 0 <= tx && tx < 8 && dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                from[ty][tx] = { y, x };
                q.push({ ty, tx });
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char startY, startX, finishY, finishX;
    cin >> startX >> startY >> finishX >> finishY;

    bfs(startY - '1', startX - 'a', finishY - '1', finishX - 'a');
}