#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, vector<int>> dijkstra(vector<vector<pair<int, int>>> &graph) {
    vector<int> dist(graph.size(), 1e9);
    dist[0] = 0;
    vector<int> from(graph.size(), -1);
    set<pair<int, int>> q = { { dist[0], 0 } };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == graph.size() - 1) {
            vector<int> path;
            for (int v = graph.size() - 1; v != -1; v = from[v])
                path.push_back(v);
            reverse(path.begin(), path.end());
            return { dist.back(), path};
        }

        for (auto &[to, weight] : graph[v]) {
            if (dist[to] > dist[v] + weight) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + weight;
                from[to] = v;
                q.insert({ dist[to], to });
            }
        }
    }

    return { -1, {} };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;
    vertexCount += 2;
    
    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int v = 1; v < vertexCount - 1; v++) {
        int type;
        cin >> type;

        if (type == 1)
            graph[0].push_back({ v, 0 });
        else if (type == 2)
            graph[v].push_back({ graph.size() - 1, 0 });
    }

    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;

        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    auto [dist, path] = dijkstra(graph);

    if (dist != -1)
        cout << path[1] << " " << path[path.size() - 2] << " " << dist;
    else
        cout << -1;
}