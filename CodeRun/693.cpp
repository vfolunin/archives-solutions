#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited) {
    if (visited[y][x])
        return visited[y][x];
    visited[y][x] = 1;

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };
    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[y][x] + 1 == a[ty][tx])
            visited[y][x] = max(visited[y][x], 1 + rec(a, ty, tx, visited));
    }

    return visited[y][x];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    vector<vector<int>> visited(h, vector<int>(w));
    int res = 0;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res = max(res, rec(a, y, x, visited));

    cout << res;
}