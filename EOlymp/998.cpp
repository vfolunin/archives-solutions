#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> bfs(vector<vector<int>> &a, vector<pair<int, int>> &start) {
    int h = a.size(), w = a[0].size();

    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    queue<pair<int, int>> q;

    for (auto &[y, x] : start) {
        dist[y][x] = 0;
        q.push({ y, x });
    }

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < h && 0 <= tx && tx < w && dist[ty][tx] > dist[y][x] + 1) {
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

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    vector<pair<int, int>> start;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            if (a[y][x])
                start.push_back({ y, x });
        }
    }

    vector<vector<int>> dist = bfs(a, start);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << dist[y][x] << " ";
        cout << "\n";
    }
}