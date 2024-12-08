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
        if (visited[to] == 0)
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
    for (int v = 0; v < graph.size(); v++)
        if (!visited[v])
            dfs(graph, v, visited, order);
    reverse(order.begin(), order.end());

    vector<int> dist(vertexCount);
    for (int v : order)
        for (int to : graph[v])
            dist[to] = max(dist[to], dist[v] + 1);

    cout << *max_element(dist.begin(), dist.end());
}