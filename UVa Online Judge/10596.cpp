#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

bool solve() {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int v = 0;
    while (v < vertexCount && graph[v].empty())
        v++;

    vector<int> visited(vertexCount);
    if (v < vertexCount)
        dfs(graph, v, visited);

    bool ok = edgeCount;
    for (int v = 0; ok && v < vertexCount; v++) {
        ok &= graph[v].size() % 2 == 0;
        ok &= graph[v].empty() || visited[v];
    }

    if (ok)
        cout << "Possible\n";
    else
        cout << "Not Possible\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}