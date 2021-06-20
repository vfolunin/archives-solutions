#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &a, vector<vector<int>> &graph, int v, vector<int> &res) {
    res[v] = 0;
    for (int to : graph[v]) {
        if (res[to] == -1)
            dfs(a, graph, to, res);
        res[v] = max(res[v], res[to]);
    }
    res[v] += a[v / a.size()][v % a.size()];
}

void solve(int test) {
    int size, maxJump;
    cin >> size >> maxJump;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    vector<vector<int>> graph(size * size);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            for (int ty = 0; ty < size; ty++)
                if (abs(y - ty) <= maxJump && a[y][x] < a[ty][x])
                    graph[y * size + x].push_back(ty * size + x);

            for (int tx = 0; tx < size; tx++)
                if (abs(x - tx) <= maxJump && a[y][x] < a[y][tx])
                    graph[y * size + x].push_back(y * size + tx);
        }
    }

    vector<int> res(size * size, -1);
    dfs(a, graph, 0, res);

    if (test)
        cout << "\n";
    cout << res[0] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}