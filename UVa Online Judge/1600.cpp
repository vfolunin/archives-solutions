#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &a, int limit) {
    vector<vector<vector<int>>> dist(a.size(), vector<vector<int>>(a[0].size(), vector<int>(limit + 1, 1e9)));
    dist[0][0][0] = 0;

    queue<int> q;
    q.push(0);
    q.push(0);
    q.push(0);

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();
        int l = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d], tl = a[y][x] ? l + 1 : 0;
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && tl <= limit && dist[ty][tx][tl] == 1e9) {
                dist[ty][tx][tl] = dist[y][x][l] + 1;
                q.push(ty);
                q.push(tx);
                q.push(tl);
            }
        }
    }

    return *min_element(dist[a.size() - 1][a[0].size() - 1].begin(), dist[a.size() - 1][a[0].size() - 1].end());
}

void solve() {
    int height, width, limit;
    cin >> height >> width >> limit;

    vector<vector<int>> a(height, vector<int>(width));
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            cin >> a[y][x];

    int res = bfs(a, limit);
    if (res == 1e9)
        res = -1;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}