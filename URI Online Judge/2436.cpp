#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited) {
    visited[y][x] = 1;

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() &&
            a[ty][tx] == 1 && !visited[ty][tx])
            return dfs(a, ty, tx, visited);
    }

    return { y, x };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, y, x;
    cin >> h >> w >> y >> x;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    vector<vector<int>> visited(h, vector<int>(w));
    auto [resY, resX] = dfs(a, y - 1, x - 1, visited);
    cout << resY + 1 << " " << resX + 1 << "\n";
}