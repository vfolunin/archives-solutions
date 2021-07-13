#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &dirs) {
    vector<vector<vector<int>>> dist(dirs.size(), vector<vector<int>>(dirs[0].size(), vector<int>(4, 1e9)));
    queue<int> q;

    dist[0][0][0] = 0;
    q.push(0);
    q.push(0);
    q.push(0);

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();
        int t = q.front();
        q.pop();

        int dy[] = { -1, 0, 1, 0 };
        int dx[] = { 0, 1, 0, -1 };

        for (int i = 0; i < 4; i++) {
            if (!(dirs[y][x] & (1 << i)))
                continue;
            int d = (t + i) % 4;

            int ty = y + dy[d], tx = x + dx[d], tt = (t + 1) % 4;
            if (0 <= ty && ty < dirs.size() && 0 <= tx && tx < dirs[0].size() && dist[ty][tx][tt] == 1e9) {
                dist[ty][tx][tt] = dist[y][x][t] + 1;
                q.push(ty);
                q.push(tx);
                q.push(tt);
            }
        }
    }

    return *min_element(dist.back().back().begin(), dist.back().back().end());
}

bool solve() {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    string dc = "NESW";
    vector<vector<int>> dirs(h, vector<int>(w));

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y == h - 1 && x == w - 1)
                continue;

            string s;
            cin >> s;

            for (int i = 0; i < 4; i++)
                if (s.find(dc[i]) != -1)
                    dirs[y][x] |= 1 << i;
        }
    }

    int res = bfs(dirs);

    if (res != 1e9)
        cout << res << "\n";
    else
        cout << "no path to exit\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}