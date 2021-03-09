#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(vector<vector<int>> &graph, int v, int c, vector<int> &visited) {
    visited[v] = c;
    for (int to : graph[v])
        if (visited[to] == c || !visited[to] && !dfs(graph, to, 3 - c, visited))
            return 0;
    return 1;
}

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> graph(vertexCount);

    while (1) {
        int a, b;
        cin >> a >> b;

        if (!a && !b)
            break;

        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    vector<int> visited(vertexCount);
    bool ok = 1;
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            ok &= dfs(graph, v, 1, visited);
    
    cout << (ok ? "YES\n" : "NO\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}