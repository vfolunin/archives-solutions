#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color) {
    visited[v] = color;
    for (int to : graph[v]) {
        if (!visited[to] && dfs(graph, to, visited, 3 - color))
            return 1;
        if (visited[to] == visited[v])
            return 1;
    }
    return 0;
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

        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    vector<int> visited(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v] && dfs(graph, v, visited, 1)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (int color : visited)
        cout << color << " ";
}