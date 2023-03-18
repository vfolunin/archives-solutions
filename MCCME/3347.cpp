#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish) {
    vector<long long> dist(graph.size(), 1e18);
    dist[start] = 0;
    set<pair<long long, int>> q = { { dist[start], start } };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == finish)
            return dist[finish];

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
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;

        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    int start, finish;
    cin >> start >> finish;
    start--;
    finish--;

    cout << dijkstra(graph, start, finish);
}