#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> bfs(int h, int w, int y, int x) {
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int, int>> q;

    dist[y][x] = 0;
    q.push({ y, x });

    vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
    vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();        

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < h && 0 <= tx && tx < w && dist[ty][tx] == -1) {
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

    int h, w, sy, sx;
    cin >> h >> w >> sy >> sx;
    sy--;
    sx--;

    vector<vector<int>> dist = bfs(h, w, sy, sx);

    int queryCount;
    cin >> queryCount;

    int res = 0;
    for (int i = 0; i < queryCount; i++) {
        int y, x;
        cin >> y >> x;
        y--;
        x--;

        if (dist[y][x] != -1) {
            res += dist[y][x];
        } else {
            cout << -1;
            return 0;
        }
    }

    cout << res;
}