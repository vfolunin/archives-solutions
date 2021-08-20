#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int startVertex) {
    vector<int> dist(graph.size(), 1e9);
    dist[startVertex] = 0;
    set<pair<int, int>> q = { { dist[startVertex], startVertex } };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist;
}

bool solve() {
    int vertexCount, edgeCount, routeVertexCount, startVertex;
    cin >> vertexCount >> edgeCount >> routeVertexCount >> startVertex;

    if (!vertexCount)
        return 0;

    vector<vector<pair<int, int>>> graph1(vertexCount);
    vector<int> route(routeVertexCount - 1);

    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        if (a > b)
            swap(a, b);

        graph1[a].push_back({ b, w });
        graph1[b].push_back({ a, w });

        if (a + 1 == b && b < routeVertexCount)
            route[a] = w;
    }

    vector<vector<pair<int, int>>> graph2(vertexCount);

    for (int v = 0; v < routeVertexCount - 1; v++)
        graph2[v].push_back({ v + 1, route[v] });

    for (int v = 0; v < vertexCount; v++)
        if (v >= routeVertexCount)
            for (auto &[to, w] : graph1[v])
                graph2[v].push_back({ to, w });

    vector<int> dist = dijkstra(graph2, startVertex);
    
    cout << dist[routeVertexCount - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}