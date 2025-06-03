#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color, bool &isBipartite) {
    visited[v] = color;
    for (int to : graph[v]) {
        if (!visited[to])
            dfs(graph, to, visited, 3 - color, isBipartite);
        else if (visited[to] == visited[v])
            isBipartite = 0;
    }
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

    vector<int> visited(vertexCount);
    bool isBipartite = 1;

    for (int v = 0; v < vertexCount && isBipartite; v++)
        if (!visited[v])
            dfs(graph, v, visited, 1, isBipartite);

    cout << (isBipartite ? "BICOLORABLE\n" : "NOT BICOLORABLE\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}