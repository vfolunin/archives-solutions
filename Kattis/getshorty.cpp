#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<double> dijkstra(vector<vector<pair<int, double>>> &graph, int start) {
    vector<double> dist(graph.size());
    dist[start] = 1;
    set<pair<int, int>> q = { {dist[start], start} };

    while (!q.empty()) {
        int v = (--q.end())->second;
        q.erase(--q.end());

        for (auto &[to, w] : graph[v]) {
            if (dist[to] < dist[v] * w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] * w;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist;
}

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount)
        return 0;

    vector<vector<pair<int, double>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        double w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    cout.precision(4);
    cout << fixed << dijkstra(graph, 0).back() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}