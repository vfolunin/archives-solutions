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
    set<pair<int, int>> q = { {dist[start], start} };

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
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    vector<vector<pair<int, int>>> graph(vertexCount * 2);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    vector<int> distA = dijkstra(graph, 0);
    vector<int> distB = dijkstra(graph, vertexCount - 1);

    int res = 0;
    for (int v = 0; v < vertexCount; v++)
        for (auto &[to, w] : graph[v])
            if (distA[v] + w + distB[to] == distA[vertexCount - 1])
                res += w;

    cout << res * 2 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}