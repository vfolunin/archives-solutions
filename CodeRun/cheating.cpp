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
        if (visited[to] == 0)
            dfs(graph, to, visited, 3 - color, isBipartite);
        else if (visited[to] == color)
            isBipartite = 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

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
    bool isBipartite = 1;
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, visited, 1, isBipartite);

    cout << (isBipartite ? "YES" : "NO");
}