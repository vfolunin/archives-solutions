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
    int vertexCount, edgeCount, queryCount, start;
    cin >> vertexCount >> edgeCount >> queryCount >> start;

    if (!vertexCount)
        return 0;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
    }

    vector<int> dist = dijkstra(graph, start);

    for (int i = 0; i < queryCount; i++) {
        int v;
        cin >> v;
        if (dist[v] != 1e9)
            cout << dist[v] << "\n";
        else
            cout << "Impossible\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}