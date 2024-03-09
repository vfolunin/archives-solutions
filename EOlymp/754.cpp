#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a, int startY, int startX, int finishY, int finishX) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    queue<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push({ startY, startX });

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (y == finishY && x == finishX)
            return dist[y][x];

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() &&
                (a[ty][tx] != 'X' || ty == finishY && tx == finishX) && dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
            }
        }
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int w, h;
    cin >> w >> h;
    h += 2;
    w += 2;

    vector<string> a(h, string(w, '.'));
    for (int y = 1; y < h - 1; y++)
        for (int x = 1; x < w - 1; x++)
            cin >> a[y][x];

    for (int x1, y1, x2, y2; (cin >> x1 >> y1 >> x2 >> y2) && x1; )
        cout << bfs(a, y1, x1, y2, x2) << "\n";
}