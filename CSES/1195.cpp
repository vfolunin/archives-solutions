#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>> &graph, int startVertex) {
    vector<long long> dist(graph.size(), 1e18);
    dist[startVertex] = 0;
    set<pair<long long, int>> q = { { dist[startVertex], startVertex } };

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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<pair<int, int>>> graph(vertexCount * 2);

    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;

        graph[a].push_back({ b, w });
        graph[a].push_back({ b + vertexCount, w / 2 });
        graph[a + vertexCount].push_back({ b + vertexCount, w });
    }

    vector<long long> dist = dijkstra(graph, 0);

    cout << min(dist[vertexCount - 1], dist[2 * vertexCount - 1]);
}