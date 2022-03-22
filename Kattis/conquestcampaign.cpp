#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(int h, int w, vector<pair<int, int>> &startCells) {
    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    queue<int> q;

    for (auto &[sy, sx] : startCells) {
        dist[sy][sx] = 0;
        q.push(sy);
        q.push(sx);
    }

    int maxDist = 0;
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();
        maxDist = max(maxDist, dist[y][x]);

        static int dy[] = { -1, 0, 1, 0 };
        static int dx[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < h && 0 <= tx && tx < w && dist[ty][tx] == 1e9) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    return maxDist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, startCellCount;
    cin >> h >> w >> startCellCount;

    vector<pair<int, int>> startCells(startCellCount);
    for (auto &[y, x] : startCells) {
        cin >> y >> x;
        y--;
        x--;
    }

    cout << bfs(h, w, startCells) + 1;
}