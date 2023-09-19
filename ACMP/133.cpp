#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9);
    dist[start] = 0;
    set<pair<int, int>> q = { { dist[start], start } };

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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<int> cost(vertexCount);
    for (int &c : cost)
        cin >> c;

    int edgeCount;
    cin >> edgeCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back({ b, cost[a] });
        graph[b].push_back({ a, cost[b] });
    }

    vector<int> dist = dijkstra(graph, 0);

    cout << (dist.back() != 1e9 ? dist.back() : -1);
}