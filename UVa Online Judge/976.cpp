#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<string> &a, int y, int x) {
    a[y][x] = '*';

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == '#')
            dfs(a, ty, tx);
    }
}

bool solve() {
    int h, w, bridgeCount, dist;
    if (!(cin >> h >> w >> bridgeCount >> dist))
        return 0;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    dfs(a, 0, 0);

    vector<int> y1(w, -1), y2(w, -1);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == '*')
                y1[x] = y;
            if (a[y][x] == '#' && y2[x] == -1)
                y2[x] = y;
        }
    }

    vector<vector<int>> res(w, vector<int>(bridgeCount + 1, 1e9));
    for (int x = 0; x < w; x++) {
        res[x][1] = y2[x] - y1[x] - 1;
        if (x)
            res[x][1] = min(res[x][1], res[x - 1][1]);

        for (int bridges = 2; bridges <= bridgeCount; bridges++) {
            if (x)
                res[x][bridges] = min(res[x][bridges], res[x - 1][bridges]);
            if (dist < x)
                res[x][bridges] = min(res[x][bridges], res[x - dist - 1][bridges - 1] + y2[x] - y1[x] - 1);
        }
    }

    cout << res[w - 1][bridgeCount] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}