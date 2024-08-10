#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<double> dijkstra(vector<vector<pair<int, double>>> &graph, int start) {
    vector<double> dist(graph.size(), 1e9);
    set<pair<int, int>> q;

    dist[start] = 0;
    q.insert({ dist[start], start });

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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, a, b, c;
    double price;
    cin >> vertexCount >> a >> b >> c >> price >> edgeCount;
    a--;
    b--;
    c--;

    vector<vector<pair<int, double>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        double weight;
        cin >> a >> b >> weight;
        a--;
        b--;

        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    vector<double> distA = dijkstra(graph, a);
    vector<double> distB = dijkstra(graph, b);

    if (distA[b] == 1e9 || distB[c] == 1e9 || distA[c] == 1e9)
        cout << -1;
    else
        cout << fixed << (distA[b] + distB[c] - distA[c]) * price;
}