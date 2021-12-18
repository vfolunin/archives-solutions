#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited) {
    visited[y][x] = 1;
    int res = 1;

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() &&
            a[y][x] <= a[ty][tx] && !visited[ty][tx])
            res += dfs(a, ty, tx, visited);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, y, x;
    cin >> size >> y >> x;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    vector<vector<int>> visited(size, vector<int>(size));
    cout << dfs(a, y - 1, x - 1, visited) << "\n";
}