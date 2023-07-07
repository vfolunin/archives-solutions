#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> bfs(vector<vector<int>> &a, int startY, int startX) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    queue<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push({ startY, startX });

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && !a[ty][tx] && dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
            }
        }
    }

    return dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int h, w, start1Y, start1X, start2Y, start2X;
    cin >> h >> w >> start1Y >> start1X >> start2Y >> start2X;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    vector<vector<int>> dist1 = bfs(a, start1Y - 1, start1X - 1);
    vector<vector<int>> dist2 = bfs(a, start2Y - 1, start2X - 1);

    int resY = -1, resX = -1;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (dist1[y][x] == 1e9 || dist2[y][x] == 1e9)
                continue;
            if (resY == -1 || max(dist1[resY][resX], dist2[resY][resX]) > max(dist1[y][x], dist2[y][x])) {
                resY = y;
                resX = x;
            }
        }
    }

    if (resY == -1)
        cout << -1;
    else
        cout << resY + 1 << " " << resX + 1;
}