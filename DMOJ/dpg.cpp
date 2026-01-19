#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (!visited[to])
            dfs(graph, to, visited);
        visited[v] = max(visited[v], 1 + visited[to]);
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
    }

    vector<int> visited(graph.size());
    for (int v = 0; v < graph.size(); v++)
        if (!visited[v])
            dfs(graph, v, visited);

    cout << *max_element(visited.begin(), visited.end()) - 1;
}