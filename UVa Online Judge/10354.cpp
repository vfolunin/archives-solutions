#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int startVertex) {
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

    return dist;
}

bool solve() {
    int vertexCount, edgeCount, a, b, c, d;
    if (!(cin >> vertexCount >> edgeCount >> a >> b >> c >> d))
        return 0;
    a--;
    b--;
    c--;
    d--;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a - 1].push_back({ b - 1, w });
        graph[b - 1].push_back({ a - 1, w });
    }

    vector<int> distA = dijkstra(graph, a);
    vector<int> distB = dijkstra(graph, b);

    vector<vector<pair<int, int>>> graph2(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        if (distA[v] + distB[v] == distA[b])
            continue;
        for (auto &[to, w] : graph[v])
            if (distA[v] + w + distB[to] != distA[b] && distA[to] + w + distB[v] != distA[b])
                graph2[v].push_back({ to, w });
    }

    vector<int> distC = dijkstra(graph2, c);

    if (distA[c] + distB[c] == distA[b] || distA[d] + distB[d] == distA[b] || distC[d] == 1e9)
        cout << "MISSION IMPOSSIBLE.\n";
    else
        cout << distC[d] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}