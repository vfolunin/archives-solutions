#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9);
    dist[start] = 0;
    set<pair<int, int>> q = { { dist[start], start } };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, weight] : graph[v]) {
            if (dist[to] > dist[v] + weight) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + weight;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<pair<int, int>>> graph(vertexCount), graphR(vertexCount);
    vector<tuple<int, int, int>> selectedEdges;

    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        string type;
        cin >> a >> b >> weight >> type;

        graph[a].push_back({ b, weight });
        graphR[b].push_back({ a, weight });

        if (type == "A380")
            selectedEdges.push_back({ a, b, weight });
    }

    vector<int> distA = dijkstra(graph, 0);
    vector<int> distB = dijkstra(graphR, vertexCount - 1);

    int res = 1e9;
    for (auto &[a, b, weight] : selectedEdges)
        res = min(res, distA[a] + distB[b] + weight);

    cout << (res < 1e9 ? res : -1);
}