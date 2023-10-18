#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

int dijkstra(vector<vector<int>> &a) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    set<tuple<int, int, int>> q;

    dist[0][0] = a[0][0];
    q.insert({ dist[0][0], 0, 0});

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto [d, y, x] = *q.begin();
        q.erase(q.begin());

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && dist[ty][tx] > dist[y][x] + a[ty][tx]) {
                q.erase({ dist[ty][tx], ty, tx });
                dist[ty][tx] = dist[y][x] + a[ty][tx];
                q.insert({ dist[ty][tx], ty, tx });
            }
        }
    }

    return dist.back().back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    cout << dijkstra(a);
}