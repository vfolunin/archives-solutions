#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    int res = 1;
    for (int to : graph[v])
        if (!visited[to])
            res += dfs(graph, to, visited);
    return res;
}

void solve() {
    int vertexCount, edgeCount, weight1, weight2;
    cin >> vertexCount >> edgeCount >> weight1 >> weight2;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(vertexCount);
    long long res = 0;
    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v]) {
            int count = dfs(graph, v, visited);
            res += weight1 + min(weight1, weight2) * (count - 1LL);
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