#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &a, int y, int x) {
    a[y][x] = 1;

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() && !a[ty][tx])
            dfs(a, ty, tx);
    }
}

void solve() {
    vector<vector<int>> a(5, vector<int>(5));
    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
            cin >> a[y][x];

    dfs(a, 0, 0);

    cout << (a[4][4] ? "COPS\n" : "ROBBERS\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}