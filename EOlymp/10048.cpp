#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    set<pair<int, int>> q;

    dist[start] = 0;
    q.insert({ dist[start], start });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == finish)
            return dist[v];

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back({ b, 0 });
        graph[b].push_back({ a, 1 });
    }

    cout << dijkstra(graph, 0, vertexCount - 1);
}