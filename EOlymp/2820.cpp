#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(int startY, int startX, int finishY, int finishX) {
    vector<vector<int>> dist(8, vector<int>(8, 1e9));
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

            if (0 <= ty && ty < dist.size() && 0 <= tx && tx < dist.size() && dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
            }
        }
    }

    return dist[finishY][finishX];
}

bool solve() {
    char startX, startY, finishX, finishY;
    if (!(cin >> startX >> startY >> finishX >> finishY))
        return 0;

    cout << "To get from " << startX << startY << " to " << finishX << finishY;
    cout << " takes " << bfs(startY - '1', startX - 'a', finishY - '1', finishX - 'a') << " knight moves.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}