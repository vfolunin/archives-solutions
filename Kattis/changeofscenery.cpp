#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    vector<int> count(graph.size(), 0);
    set<pair<int, int>> q;

    dist[start] = 0;
    count[start] = 1;
    q.insert({ dist[start], start });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == finish)
            return count[v];

        for (auto &[to, weight] : graph[v]) {
            if (dist[to] > dist[v] + weight) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + weight;
                count[to] = count[v];
                q.insert({ dist[to], to });
            } else if (dist[to] == dist[v] + weight) {
                count[to] = min(count[to] + count[v], (int)1e9);
            }
        }
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, dist;
    cin >> vertexCount >> edgeCount >> dist;

    for (int i = 0; i < dist; i++) {
        int v;
        cin >> v;
    }

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;

        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    cout << (dijkstra(graph, 0, vertexCount - 1) > 1 ? "yes" : "no");
}