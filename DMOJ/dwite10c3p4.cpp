#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a) {
    int h = a.size(), w = a[0].size();

    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    queue<pair<int, int>> q;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == 'F') {
                dist[y][x] = 0;
                q.push({ y, x });
            }
        }
    }

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] == 'T' && dist[ty][tx] > dist[y][x] + 1) {
                a[ty][tx] = 'F';
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
            }
        }
    }

    int res = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == 'F')
                res = max(res, dist[y][x]);
            else if (a[y][x] == 'T')
                return -1;
        }
    }
    return res;
}

bool solve() {
    vector<string> a(11);
    for (string &s : a)
        if (!(cin >> s))
            return 0;

    cout << bfs(a) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}