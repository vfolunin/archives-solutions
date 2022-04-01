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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, start, finish;
    cin >> vertexCount >> start >> finish;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int w;
            cin >> w;
            graph[a].push_back({ b, w });
        }
    }

    vector<int> dist = dijkstra(graph, start);

    cout << dist[finish];
}