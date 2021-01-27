#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color) {
    visited[v] = color;
    int k0 = color == 0, k1 = color == 1;
    for (int to : graph[v]) {
        if (visited[to] == -1) {
            auto [tk0, tk1] = dfs(graph, to, visited, !color);
            if (tk0 == -1)
                return { -1, -1 };
            k0 += tk0;
            k1 += tk1;
        } else if (visited[to] == color) {
            return { -1, -1 };
        }
    }
    return { k0, k1 };
}

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(vertexCount, -1);
    int res = 0;

    for (int v = 0; v < vertexCount; v++) {
        if (visited[v] == -1) {
            auto [k0, k1] = dfs(graph, v, visited, 0);
            if (k0 == -1) {
                cout << "-1\n";
                return;
            }
            res += max(min(k0, k1), 1);
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}