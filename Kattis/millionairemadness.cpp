#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited, int limit) {
    visited[y][x] = 1;

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() &&
            !visited[ty][tx] && a[ty][tx] - a[y][x] <= limit)
            dfs(a, ty, tx, visited, limit);
    }
}

bool can(vector<vector<int>> &a, int limit) {
    vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
    dfs(a, 0, 0, visited, limit);
    return visited.back().back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (vector<int> &row : a)
        for (int &value : row)
            cin >> value;

    int l = -1, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(a, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}