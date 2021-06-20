#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &a, int sy, int sx, int sd, int fy, int fx) {
    vector<vector<vector<int>>> dist(a.size(), vector<vector<int>>(a[0].size(), vector<int>(4, 1e9)));
    queue<int> q;

    if (sy <= 0 || sy >= a.size() || sx <= 0 || sx >= a[0].size() ||
        a[sy - 1][sx - 1] || a[sy - 1][sx] || a[sy][sx - 1] || a[sy][sx])
        return 1e9;

    dist[sy][sx][sd] = 0;
    q.push(sy);
    q.push(sx);
    q.push(sd);

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();
        int d = q.front();
        q.pop();

        int td = (d + 1) % 4;
        if (dist[y][x][td] == 1e9) {
            dist[y][x][td] = dist[y][x][d] + 1;
            q.push(y);
            q.push(x);
            q.push(td);
        }

        td = (d + 3) % 4;
        if (dist[y][x][td] == 1e9) {
            dist[y][x][td] = dist[y][x][d] + 1;
            q.push(y);
            q.push(x);
            q.push(td);
        }

        for (int step = 1; step <= 3; step++) {
            int ty = y + dy[d] * step;
            int tx = x + dx[d] * step;
            if (ty <= 0 || ty >= a.size() || tx <= 0 || tx >= a[0].size() ||
                a[ty - 1][tx - 1] || a[ty - 1][tx] || a[ty][tx - 1] || a[ty][tx])
                break;
            if (dist[ty][tx][d] == 1e9) {
                dist[ty][tx][d] = dist[y][x][d] + 1;
                q.push(ty);
                q.push(tx);
                q.push(d);
            }
        }
    }

    return *min_element(dist[fy][fx].begin(), dist[fy][fx].end());
}

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    int startY, startX, finishY, finishX;
    string direction;
    cin >> startY >> startX >> finishY >> finishX >> direction;

    static vector<string> directions = { "north", "east", "south", "west" };
    int startD = find(directions.begin(), directions.end(), direction) - directions.begin();

    int res = bfs(a, startY, startX, startD, finishY, finishX);

    cout << (res != 1e9 ? res : -1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}