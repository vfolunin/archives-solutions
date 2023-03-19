#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &graph, int v, vector<int> &visited, vector<int> &order) {
    visited[v] = 1;
    for (auto &[to, w] : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, order);
    order.push_back(v);
}

int topSortShortestPaths(vector<vector<pair<int, int>>> &graph, int start, int finish) {
    vector<int> visited(graph.size()), order;
    for (int v = 0; v < graph.size(); v++)
        if (!visited[v])
            dfs(graph, v, visited, order);
    reverse(order.begin(), order.end());

    vector<int> dist(graph.size(), 1e9);
    dist[start] = 0;
    for (int v : order)
        for (auto [to, w] : graph[v])
            if (dist[v] != 1e9 && dist[to] > dist[v] + w)
                dist[to] = dist[v] + w;
    return dist[finish];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, start, finish;
    cin >> vertexCount >> edgeCount >> start >> finish;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a - 1].push_back({ b - 1, w });
    }

    int res = topSortShortestPaths(graph, start - 1, finish - 1);
    if (res != 1e9)
        cout << res;
    else
        cout << "Unreachable";
}