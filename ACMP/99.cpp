#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

int bfs(vector<vector<string>> &a, int startZ, int startY, int startX, int finishZ, int finishY, int finishX) {
    vector<vector<vector<int>>> dist(a.size(), vector<vector<int>>(a[0].size(), vector<int>(a[0][0].size(), 1e9)));
    queue<tuple<int, int, int>> q;

    dist[startZ][startY][startX] = 0;
    q.push({ startZ, startY, startX });

    vector<int> dz = { 0, 0, 0, 0, 1 };
    vector<int> dy = { -1, 0, 1, 0, 0 };
    vector<int> dx = { 0, 1, 0, -1, 0 };

    while (!q.empty()) {
        auto [z, y, x] = q.front();
        q.pop();

        for (int d = 0; d < dz.size(); d++) {
            int tz = z + dz[d];
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= tz && tz < a.size() && 0 <= ty && ty < a[0].size() && 0 <= tx && tx < a[0][0].size() && a[tz][ty][tx] != 'o') {
                a[tz][ty][tx] = 'o';
                dist[tz][ty][tx] = dist[z][y][x] + 1;
                q.push({ tz, ty, tx });
            }
        }
    }

    return dist[finishZ][finishY][finishX];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int zSize, ySize, xSize;
    cin >> zSize >> ySize >> xSize;

    vector<vector<string>> a(zSize, vector<string>(ySize));
    int startZ, startY, startX, finishZ, finishY, finishX;

    for (int z = 0; z < zSize; z++) {
        for (int y = 0; y < ySize; y++) {
            cin >> a[z][y];

            if (int x = a[z][y].find('1'); x != -1) {
                startZ = z;
                startY = y;
                startX = x;
            }
            if (int x = a[z][y].find('2'); x != -1) {
                finishZ = z;
                finishY = y;
                finishX = x;
            }
        }
    }

    cout << bfs(a, startZ, startY, startX, finishZ, finishY, finishX) * 5;
}