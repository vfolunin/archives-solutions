#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    queue<pair<int, int>> q;

    dist[0][0] = 0;
    q.push({ 0, 0 });
    int res = dist[0][0];

    vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#' && dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
                res = max(res, dist[ty][tx]);
            }
        }
    }

    return res;
}

void solve() {
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    cout << bfs(a) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}