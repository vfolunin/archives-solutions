#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<pair<int, int>> bfs(int size, int startY, int startX, int finishY, int finishX) {
    vector<vector<int>> dist(size, vector<int>(size, 1e9));
    vector<vector<pair<int, int>>> from(size, vector<pair<int, int>>(size, { -1, -1 }));
    queue<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push({ startY, startX });

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        static vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
        static vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < size && 0 <= tx && tx < size && dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                from[ty][tx] = { y, x };
                q.push({ ty, tx });
            }
        }
    }

    vector<pair<int, int>> path(dist[finishY][finishX] + 1);
    path.back() = { finishY, finishX };
    for (int i = (int)path.size() - 2; i >= 0; i--)
        path[i] = from[path[i + 1].first][path[i + 1].second];
    return path;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, startY, startX, finishY, finishX;
    cin >> size >> startY >> startX >> finishY >> finishX;

    vector<pair<int, int>> path = bfs(size, startY - 1, startX - 1, finishY - 1, finishX - 1);

    cout << path.size() - 1 << "\n";
    for (auto &[y, x] : path)
        cout << y + 1 << " " << x + 1 << "\n";
}