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
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    vector<vector<pair<int, int>>> graph(vertexCount * 2);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;

        graph[2 * a].push_back({ 2 * b + 1, w });
        graph[2 * a + 1].push_back({ 2 * b, w });
        graph[2 * b].push_back({ 2 * a + 1, w });
        graph[2 * b + 1].push_back({ 2 * a, w });
    }

    vector<int> dist = dijkstra(graph, 0);

    if (dist[2 * (vertexCount - 1)] != 1e9)
        cout << dist[2 * (vertexCount - 1)] << "\n";
    else
        cout << "-1\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}