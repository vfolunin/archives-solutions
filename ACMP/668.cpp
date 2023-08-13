#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(int startY, int startX) {
    vector<vector<int>> dist(startY + 10, vector<int>(startX + 10, 1e9));
    queue<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push({ startY, startX });

    vector<int> needY = { 0, 0, 2 };
    vector<int> needX = { 1, 2, 0 };
    vector<int> dy = { 0, 1, -2 };
    vector<int> dx = { 1, -2, 0 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (!y && !x)
            return dist[y][x];

        for (int d = 0; d < dy.size(); d++) {
            if (y < needY[d] || x < needX[d])
                continue;

            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < dist.size() && 0 <= tx && tx < dist[0].size() && dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int startY, startX;
    cin >> startY >> startX;

    cout << bfs(startY, startX);
}