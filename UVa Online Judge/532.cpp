#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int l, h, w;
    cin >> l >> h >> w;

    if (!l && !h && !w)
        return 0;

    int startZ, startY, startX;
    int finishZ, finishY, finishX;

    vector<vector<string>> a(l, vector<string>(h));
    for (int z = 0; z < l; z++) {
        for (int y = 0; y < h; y++) {
            cin >> a[z][y];
            if (int x = a[z][y].find('S'); x != -1) {
                startZ = z;
                startY = y;
                startX = x;
            }
            if (int x = a[z][y].find('E'); x != -1) {
                finishZ = z;
                finishY = y;
                finishX = x;
            }
        }
    }

    vector<vector<vector<int>>> dist(l, vector<vector<int>>(h, vector<int>(w, -1)));
    dist[startZ][startY][startX] = 0;
    queue<int> q;
    q.push(startZ);
    q.push(startY);
    q.push(startX);

    static int dz[] = { -1, 0, 0, 0, 0, 1 };
    static int dy[] = { 0, -1, 0, 1, 0, 0 };
    static int dx[] = { 0, 0, 1, 0, -1, 0 };

    while (!q.empty()) {
        int z = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 6; d++) {
            int tz = z + dz[d], ty = y + dy[d], tx = x + dx[d];
            if (0 <= tz && tz < l && 0 <= ty && ty < h && 0 <= tx && tx < w &&
                a[tz][ty][tx] != '#' && dist[tz][ty][tx] == -1) {
                dist[tz][ty][tx] = dist[z][y][x] + 1;
                q.push(tz);
                q.push(ty);
                q.push(tx);
            }
        }
    }

    if (dist[finishZ][finishY][finishX] != -1)
        cout << "Escaped in " << dist[finishZ][finishY][finishX] << " minute(s).\n";
    else
        cout << "Trapped!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}