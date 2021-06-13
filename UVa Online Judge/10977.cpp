#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &a) {
    if (a[0][0])
        return -1;

    queue<int> q;
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), -1));

    q.push(0);
    q.push(0);
    dist[0][0] = 0;

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && !a[ty][tx]) {
                if (dist[ty][tx] == -1) {
                    q.push(ty);
                    q.push(tx);
                    dist[ty][tx] = dist[y][x] + 1;
                }
            }
        }
    }

    return dist[a.size() - 1][a[0].size() - 1];
}

bool solve() {
    int h, w, blockedCount;
    if (!(cin >> h >> w >> blockedCount))
        return 0;

    vector<vector<int>> a(h, vector<int>(w));

    for (int i = 0; i < blockedCount; i++) {
        int y, x;
        cin >> y >> x;
        y--;
        x--;

        a[y][x] = 1;
    }

    int singerCount;
    cin >> singerCount;

    for (int i = 0; i < singerCount; i++) {
        int sy, sx, r;
        cin >> sy >> sx >> r;
        sy--;
        sx--;

        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if ((sy - y) * (sy - y) + (sx - x) * (sx - x) <= r * r)
                    a[y][x] = 1;
    }

    int res = bfs(a);

    if (res != -1)
        cout << res << "\n";
    else
        cout << "Impossible.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}