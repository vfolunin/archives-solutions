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
            return { dist[finish], { path.rbegin(), path.rend() } };
        }

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                from[to] = v;
                q.insert({ dist[to], to });
            }
        }
    }

    return { 0, {} };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int w;
            cin >> w;

            if (w)
                graph[a].push_back({ b, w });
        }
    }

    int start, finish;
    cin >> start >> finish;

    auto [dist, path] = dijkstra(graph, start - 1, finish - 1);

    cout << dist << "\n";
    for (int v : path)
        cout << v + 1 << " ";
}