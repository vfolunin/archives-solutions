#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

int bfs(vector<string> &a, int startY, int startX, int finishY, int finishX) {
    int h = a.size(), w = a[0].size();
    vector dist(h, vector(w, vector(7, vector<int>(7, 1e9))));
    queue<tuple<int, int, int, int>> q;

    dist[startY][startX][3][3] = 0;
    q.push({ startY, startX, 0, 0 });

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto [y, x, vy, vx] = q.front();
        q.pop();

        for (int dvy = -1; dvy <= 1; dvy++) {
            for (int dvx = -1; dvx <= 1; dvx++) {
                int tvy = vy + dvy, tvx = vx + dvx;
                if (tvy < -3 || tvy > 3 || tvx < -3 || tvx > 3)
                    continue;

                int ty = y + tvy, tx = x + tvx;
                if (ty < 0 || ty >= h || tx < 0 || tx >= w || a[ty][tx] == '1' || dist[ty][tx][tvy + 3][tvx + 3] != 1e9)
                    continue;

                dist[ty][tx][tvy + 3][tvx + 3] = dist[y][x][vy + 3][vx + 3] + 1;
                q.push({ ty, tx, tvy, tvx });
            }
        }
    }

    int res = 1e9;
    for (int vy = -3; vy <= 3; vy++)
        for (int vx = -3; vx <= 3; vx++)
            res = min(res, dist[finishY][finishX][vy + 3][vx + 3]);
    return res;
}

void solve() {
    int w, h, startX, startY, finishX, finishY, obstacleCount;
    cin >> w >> h >> startX >> startY >> finishX >> finishY >> obstacleCount;

    vector<string> a(h, string(w, '0'));
    for (int i = 0; i < obstacleCount; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        for (int y = y1; y <= y2; y++)
            for (int x = x1; x <= x2; x++)
                a[y][x] = '1';
    }

    int res = bfs(a, startY, startX, finishY, finishX);

    if (res != 1e9)
        cout << "Optimal solution takes " << res << " hops.\n";
    else
        cout << "No solution.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}