#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color, bool &bipartite) {
    visited[v] = color;
    for (int to : graph[v]) {
        if (visited[to] == 0)
            dfs(graph, to, visited, 3 - color, bipartite);
        else if (visited[to] == color)
            bipartite = 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int x;
            cin >> x;
            if (!x)
                graph[a].push_back(b);
        }
    }

    vector<int> visited(vertexCount);
    bool bipartite = 1;

    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, visited, 1, bipartite);

    cout << (bipartite ? "Bazinga!\n" : "Fail!\n");
}