#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, w;
};

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

bool solve() {
    int vertexCount, edgeCount, queryCount, start;
    cin >> vertexCount >> edgeCount >> queryCount >> start;

    if (!vertexCount)
        return 0;

    vector<Edge> edges(edgeCount);
    vector<vector<int>> graph(vertexCount);

    for (auto &[a, b, w] : edges) {
        cin >> a >> b >> w;
        graph[a].push_back(b);
    }

    const int INF = 1e9;
    vector<int> dist(vertexCount, INF);
    dist[start] = 0;

    for (int i = 0; i < vertexCount - 1; i++)
        for (auto &[a, b, w] : edges)
            if (dist[a] != INF && dist[b] > dist[a] + w)
                dist[b] = max(dist[a] + w, -INF);

    vector<int> visited(vertexCount);

    for (auto &[a, b, w] : edges)
        if (dist[a] != INF && dist[b] > dist[a] + w)
            dfs(graph, b, visited);

    for (int i = 0; i < queryCount; i++) {
        int v;
        cin >> v;

        if (dist[v] == INF)
            cout << "Impossible\n";
        else if (visited[v])
            cout << "-Infinity\n";
        else
            cout << dist[v] << "\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}