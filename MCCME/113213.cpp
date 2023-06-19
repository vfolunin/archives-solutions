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

    vector<vector<pair<int, int>>> graph(vertexCount * 2);

    for (int v = 0; v < vertexCount; v++)
        graph[v].push_back({ vertexCount + v, cost[v] });

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back({ b, cost[a] });
        graph[b].push_back({ a, cost[b] });
        graph[vertexCount + a].push_back({ b, 0 });
        graph[vertexCount + b].push_back({ a, 0 });
        graph[vertexCount + a].push_back({ vertexCount + b, cost[a] });
        graph[vertexCount + b].push_back({ vertexCount + a, cost[b] });
    }

    vector<int> dist = dijkstra(graph, 0);
    int res = min(dist[vertexCount - 1], dist[vertexCount * 2 - 1]);

    cout << (res != 1e9 ? res : -1);
}