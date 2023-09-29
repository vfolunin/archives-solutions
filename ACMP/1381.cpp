#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish) {
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

            for (int v : path)
                cout << v + 1 << " ";
            return;
        }

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                from[to] = v;
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    cout << -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, start, finish;
    cin >> vertexCount >> start >> finish;
    start--;
    finish--;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int weight;
            cin >> weight;

            if (weight != -1)
                graph[a].push_back({ b, weight });
        }
    }

    dijkstra(graph, start, finish);
}