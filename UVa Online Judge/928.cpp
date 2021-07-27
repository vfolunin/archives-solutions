#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a, int sy, int sx, int fy, int fx) {
    vector<vector<vector<vector<vector<int>>>>> dist(a.size(), vector<vector<vector<vector<int>>>>(a[0].size(),
        vector<vector<vector<int>>>(4, vector<vector<int>>(3, vector<int>(3, 1e9)))));
    deque<int> q;

    for (int d = 0; d < 4; d++) {
        dist[sy][sx][d][0][0] = 0;
        q.push_back(sy);
        q.push_back(sx);
        q.push_back(d);
        q.push_back(0);
        q.push_back(0);
    }

    while (!q.empty()) {
        int y = q.front();
        q.pop_front();
        int x = q.front();
        q.pop_front();
        int d = q.front();
        q.pop_front();
        int steps = q.front();
        q.pop_front();
        int step = q.front();
        q.pop_front();

        int dy[] = { -1, 0, 1, 0 };
        int dx[] = { 0, 1, 0, -1 };

        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#') {
            if (step < steps) {
                if (dist[ty][tx][d][steps][step + 1] == 1e9) {
                    dist[ty][tx][d][steps][step + 1] = dist[y][x][d][steps][step];
                    q.push_front(step + 1);
                    q.push_front(steps);
                    q.push_front(d);
                    q.push_front(tx);
                    q.push_front(ty);
                }
            } else {
                int tsteps = (steps + 1) % 3;
                for (int td = 0; td < 4; td++) {
                    if (dist[ty][tx][td][tsteps][0] == 1e9) {
                        dist[ty][tx][td][tsteps][0] = dist[y][x][d][steps][step] + 1;
                        q.push_back(ty);
                        q.push_back(tx);
                        q.push_back(td);
                        q.push_back(tsteps);
                        q.push_back(0);
                    }
                }
            }
        }
    }

    int res = 1e9;
    for (int d = 0; d < 4; d++)
        for (int steps = 0; steps < 3; steps++)
                res = min(res, dist[fy][fx][d][steps][0]);
    return res;
}

void solve() {
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    int sy, sx, fy, fx;
    for (int y = 0; y < h; y++) {
        cin >> a[y];
        for (int x = 0; x < w; x++) {
            if (a[y][x] == 'S') {
                sy = y;
                sx = x;
            } else if (a[y][x] == 'E') {
                fy = y;
                fx = x;
            }
        }
    }

    int res = bfs(a, sy, sx, fy, fx);

    if (res == 1e9)
        cout << "NO\n";
    else
        cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}