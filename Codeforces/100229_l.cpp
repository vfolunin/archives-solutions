#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph) {
    vector<int> dist(graph.size(), 1e9);
    vector<int> from(graph.size(), -1);
    set<pair<int, int>> q;

    dist[0] = 0;
    q.insert({ dist[0], 0 });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == graph.size() - 1) {
            vector<int> path;
            for (; v != -1; v = from[v])
                path.push_back(v);
            reverse(path.begin(), path.end());

            cout << dist[graph.size() - 1] << " " << path.size() << "\n";
            for (int v : path)
                cout << v + 1 << " ";
            return;
        }

        for (auto &[to, weight] : graph[v]) {
            if (dist[to] > dist[v] + weight) {
                q.erase({ dist[to], to });
                from[to] = v;
                dist[to] = dist[v] + weight;
                q.insert({ dist[to], to });
            }
        }
    }

    cout << "impossible";
}

int main() {
    freopen("island2.in", "r", stdin);
    freopen("island2.out", "w", stdout);
 
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<int> color(vertexCount);
    for (int &color : color)
        cin >> color;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back({ b, (color[a] != color[b]) * (a % 2 ? 2 : 1) });
        graph[b].push_back({ a, (color[a] != color[b]) * (b % 2 ? 2 : 1) });
    }

    dijkstra(graph);
}