#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void bfs(vector<string> &a, int startY, int startX) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    vector<vector<pair<pair<int, int>, char>>> from(a.size(), vector<pair<pair<int, int>, char>>(a[0].size()));
    queue<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push({ startY, startX });

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    string dc = "nesw";

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (y == 0 || y == a.size() - 1 || x == 0 || x == a[0].size() - 1) {
            cout << dist[y][x] << "\n";

            string path;
            while (y != startY || x != startX) {
                auto &[py, px] = from[y][x].first;
                path += from[y][x].second;
                y = py;
                x = px;
            }
            reverse(path.begin(), path.end());

            cout << path;
            return;
        }

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != 'U' && dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                from[ty][tx] = { { y, x }, dc[d] };
                q.push({ ty, tx });
            }
        }
    }

    cout << -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;
    cin.ignore();

    vector<string> a(h);
    int startY, startX;

    for (int y = 0; y < h; y++) {
        getline(cin, a[y]);
        if (int x = a[y].find('+'); x != -1) {
            startY = y;
            startX = x;
        }
    }

    bfs(a, startY, startX);
}