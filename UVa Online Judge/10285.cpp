#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &dist) {
    if (dist[y][x])
        return dist[y][x];

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };
    
    dist[y][x] = 1;

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[ty].size() && a[y][x] > a[ty][tx])
            dist[y][x] = max(dist[y][x], dfs(a, ty, tx, dist) + 1);
    }

    return dist[y][x];
}

void solve() {
    string name;
    int h, w;
    cin >> name >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (vector<int> &row : a)
        for (int &x : row)
            cin >> x;

    vector<vector<int>> dist(h, vector<int>(w));
    int res = 0;

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res = max(res, dfs(a, y, x, dist));

    cout << name << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}