#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, vector<int>> dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    dist[start] = 0;
    vector<int> from(graph.size(), -1);
    set<pair<int, int>> q = { { dist[start], start } };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == finish) {
            vector<int> path;
            for (int v = finish; v != -1; v = from[v])
                path.push_back(v);
            reverse(path.begin(), path.end());
            return { dist[finish], path };
        }

        for (auto &[to, weight] : graph[v]) {
            if (dist[to] > dist[v] + weight) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + weight;
                from[to] = v;
                q.insert({ dist[to], to });
            }
        }
    }

    return { -1, {} };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, start, finish;
    cin >> vertexCount >> edgeCount >> start >> finish;
    start--;
    finish--;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;

        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    auto [dist, path] = dijkstra(graph, start, finish);

    cout << dist << "\n";
    for (int v : path)
        cout << v + 1 << " ";
}