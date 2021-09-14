#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a, int sy, int sx, int fy, int fx) {
    int h = a.size(), w = a[0].size();
    vector<vector<vector<vector<int>>>> dist(h,
        vector<vector<vector<int>>>(w,
            vector<vector<int>>(7, vector<int>(7, 1e9))
        )
    );
    queue<int> q;

    dist[sy][sx][3][3] = 0;
    q.push(sy);
    q.push(sx);
    q.push(0);
    q.push(0);

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();
        int vy = q.front();
        q.pop();
        int vx = q.front();
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
                q.push(ty);
                q.push(tx);
                q.push(tvy);
                q.push(tvx);
            }
        }
    }

    int res = 1e9;
    for (int vy = -3; vy <= 3; vy++)
        for (int vx = -3; vx <= 3; vx++)
            res = min(res, dist[fy][fx][vy + 3][vx + 3]);
    return res;
}

void solve() {
    int w, h, sx, sy, fx, fy, obstacleCount;
    cin >> w >> h >> sx >> sy >> fx >> fy >> obstacleCount;

    vector<string> a(h, string(w, '0'));
    for (int i = 0; i < obstacleCount; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        for (int y = y1; y <= y2; y++)
            for (int x = x1; x <= x2; x++)
                a[y][x] = '1';
    }

    int res = bfs(a, sy, sx, fy, fx);

    if (res != 1e9)
        cout << "Optimal solution takes " << res << " hops.\n";
    else
        cout << "No solution.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}