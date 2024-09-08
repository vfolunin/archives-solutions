#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, order);
    order.push_back(v);
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
    }

    vector<int> visited(vertexCount), order;
    dfs(graph, 0, visited, order);
    reverse(order.begin(), order.end());

    if (!visited.back()) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> dist(vertexCount, -1e9), from(vertexCount, -1);
    dist[0] = 0;

    for (int v : order) {
        for (int to : graph[v]) {
            if (dist[to] < dist[v] + 1) {
                dist[to] = dist[v] + 1;
                from[to] = v;
            }
        }
    }

    vector<int> path;
    for (int v = vertexCount - 1; v != -1; v = from[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int v : path)
        cout << v + 1 << " ";
}