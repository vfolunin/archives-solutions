#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void bfs(vector<vector<int>> &a, int startY, int startX,
         map<pair<int, int>, pair<int, int>> &edges, set<pair<int, int>> finishes) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    queue<pair<int, int>> q;

    dist[startY][startX] = 1;
    q.push({ startY, startX });

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (finishes.count({ y, x })) {
            cout << dist[y][x];
            return;
        }

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && !a[ty][tx] && dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
            }
        }

        if (edges.count({ y, x })) {
            auto &[ty, tx] = edges[{ y, x }];

            if (dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
            }
        }
    }

    cout << "Impossible";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, startY, startX;
    cin >> h >> w >> startY >> startX;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    int edgeCount;
    cin >> edgeCount;

    map<pair<int, int>, pair<int, int>> edges;
    for (int i = 0; i < edgeCount; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        edges[{ y1 - 1, x1 - 1 }] = { y2 - 1, x2 - 1 };
    }

    int finishCount;
    cin >> finishCount;

    set<pair<int, int>> finishes;
    for (int i = 0; i < finishCount; i++) {
        int y, x;
        cin >> y >> x;
        finishes.insert({ y - 1, x - 1 });
    }

    bfs(a, startY - 1, startX - 1, edges, finishes);
}