#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<string>> &a, int z, int y, int x) {
    vector<vector<vector<int>>> dist(a.size(), vector<vector<int>>(a.size(), vector<int>(a.size(), -1)));
    queue<tuple<int, int, int>> q;

    dist[z][y][x] = 0;
    q.push({ z, y, x });

    while (!q.empty()) {
        auto [z, y, x] = q.front();
        q.pop();

        if (!z)
            return dist[z][y][x];

        static vector<int> dz = { -1, 0, 0, 0, 0, 1 };
        static vector<int> dy = { 0, -1, 0, 1, 0, 0 };
        static vector<int> dx = { 0, 0, 1, 0, -1, 0 };

        for (int d = 0; d < dz.size(); d++) {
            int tz = z + dz[d];
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= tz && tz < a.size() &&
                0 <= ty && ty < a.size() &&
                0 <= tx && tx < a.size() &&
                a[tz][ty][tx] != '#' && dist[tz][ty][tx] == -1) {
                dist[tz][ty][tx] = dist[z][y][x] + 1;
                q.push({ tz, ty, tx });
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<string>> a(size, vector<string>(size));
    int sz, sy, sx;

    for (int z = 0; z < size; z++) {
        for (int y = 0; y < size; y++) {
            cin >> a[z][y];
            if (int x = a[z][y].find('S'); x != -1) {
                sz = z;
                sy = y;
                sx = x;
            }
        }
    }

    cout << bfs(a, sz, sy, sx);
}