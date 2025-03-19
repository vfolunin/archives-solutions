#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long dijkstra(vector<vector<pair<int, int>>> &graph, int startVertex) {
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

    long long res = 0;
    for (int d : dist)
        res += d;
    return res;
}

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<pair<int, int>>> graph(vertexCount), graphR(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a - 1].push_back({ b - 1, w });
        graphR[b - 1].push_back({ a - 1, w });
    }

    cout << dijkstra(graph, 0) + dijkstra(graphR, 0) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}