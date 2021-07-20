#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &a, int y, int x, int limit, vector<vector<int>> &visited, int &finishX) {
    if (y == a.size() - 1) {
        finishX = min(finishX, x);
        return;
    }

    visited[y][x] = 1;

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && !visited[ty][tx] &&
            (a[y][x] < limit && a[y][x] + 1 == a[ty][tx] || a[y][x] == limit && a[ty][tx] == 1)) {
            int tLimit = a[y][x] < limit ? limit : limit + 1;
            dfs(a, ty, tx, tLimit, visited, finishX);
        }
    }

    visited[y][x] = 0;
}

void solve(int test) {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    if (test)
        cout << "\n";
    for (int x = 0; x < w; x++) {
        if (a[0][x] != 1)
            continue;

        vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
        int finishX = 1e9;
        dfs(a, 0, x, 1, visited, finishX);

        if (finishX != 1e9) {
            cout << 1 << " " << x + 1 << "\n";
            cout << a.size() << " " << finishX + 1 << "\n";
            return;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}