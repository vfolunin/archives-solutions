#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<int>> &g, int v, int vColor, vector<int> &color) {
    color[v] = vColor;
    for (int to : g[v]) {
        if (!color[to]) {
            if (!dfs(g, to, 3 - vColor, color))
                return 0;
        } else if (color[to] == vColor) {
            return 0;
        }
    }
    return 1;
}

bool solve() {
    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> color(n);
    bool ok = 1;
    for (int v = 0; v < n; v++)
        if (!color[v])
            ok &= dfs(g, v, 1, color);

    cout << (ok ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}