#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<string> &a, int y, int x, vector<string> &visited, vector<string> &res) {
    visited[y][x] = 1;
    res[y][x] = a[y][x];

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size())
            res[ty][tx] = a[ty][tx];
    }

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == '0' && !visited[ty][tx])
            return 1 + dfs(a, ty, tx, visited, res);
    }
    return 0;
}

bool solve() {
    int h, w, sy, sx;
    if (!(cin >> h >> w >> sy >> sx))
        return 0;
    sy--;
    sx--;

    vector<string> a(h, string(w, ' '));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    vector<string> visited(h, string(w, 0)), res(h, string(w, '?'));
    int moveCount = dfs(a, sy, sx, visited, res);

    cout << "\n";
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << "|---";
        cout << "|\n";
        for (int x = 0; x < w; x++)
            cout << "| " << res[y][x] << " ";
        cout << "|\n";
    }
    for (int x = 0; x < w; x++)
        cout << "|---";
    cout << "|\n\nNUMBER OF MOVEMENTS: " << moveCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
