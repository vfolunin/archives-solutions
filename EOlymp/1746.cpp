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
            for (int step = 1; 1; step++) {
                int ty = y + dy[d] * step;
                int tx = x + dx[d] * step;

                if (ty < 0 || ty >= a.size() || tx < 0 || tx >= a[0].size() || a[ty][tx] == 'P')
                    break;

                if (dist[ty][tx] < dist[y][x] + 1)
                    break;

                if (dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    int startY, startX, finishY, finishX;

    for (int y = 0; y < h; y++) {
        cin >> a[y];
        for (int x = 0; x < w; x++) {
            if (a[y][x] == 'S') {
                startY = y;
                startX = x;
            } else if (a[y][x] == 'F') {
                finishY = y;
                finishX = x;
            }
        }
    }

    cout << bfs(a, startY, startX, finishY, finishX);
}