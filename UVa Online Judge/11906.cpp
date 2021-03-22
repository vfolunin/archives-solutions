#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &a, int y, int x, int step[], int res[]) {
    a[y][x] = 2;

    int dy[] = { -step[1], -step[0], step[0], step[1], step[1], step[0], -step[0], -step[1] };
    int dx[] = { step[0], step[1], step[1], step[0], -step[0], -step[1], -step[1], -step[0] };

    set<pair<int, int>> neighbors;
    for (int d = 0; d < 8; d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size()) {
            if (a[ty][tx] == 1)
                dfs(a, ty, tx, step, res);
            if (a[ty][tx] != 0)
                neighbors.insert({ ty, tx });
        }
    }

    res[neighbors.size() % 2]++;
}

void solve(int test) {
    int h, w, step[2];
    cin >> h >> w >> step[0] >> step[1];

    vector<vector<int>> a(h, vector<int>(w, 1));

    int forbiddenCellCount;
    cin >> forbiddenCellCount;

    for (int i = 0; i < forbiddenCellCount; i++) {
        int y, x;
        cin >> y >> x;
        a[y][x] = 0;
    }

    int res[2] = {};
    dfs(a, 0, 0, step, res);

    cout << "Case " << test << ": " << res[0] << " " << res[1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}