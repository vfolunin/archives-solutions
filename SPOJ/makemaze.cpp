#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<string> &a, int y, int x, vector<vector<int>> &visited) {
    visited[y][x] = 1;

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == '.' && !visited[ty][tx])
            dfs(a, ty, tx, visited);
    }
}

void solve() {
    int h, w;
    cin >> h >> w;

    vector<string> a(h, string(w, ' '));
    int exits = 0, startY, startX, finishY, finishX;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];

            if (a[y][x] == '.' && (y == 0 || y == h - 1 || x == 0 || x == w - 1)) {
                exits++;
                if (exits == 1) {
                    startY = y;
                    startX = x;
                } else if (exits == 2) {
                    finishY = y;
                    finishX = x;
                }
            }
        }
    }

    if (exits != 2) {
        cout << "invalid\n";
        return;
    }

    vector<vector<int>> visited(h, vector<int>(w));
    dfs(a, startY, startX, visited);

    cout << (visited[finishY][finishX] ? "valid\n" : "invalid\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}