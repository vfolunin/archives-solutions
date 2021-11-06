#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9);
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

bool solve() {
    int vertexCount, edgeCount, start, finish;
    if (!(cin >> vertexCount >> edgeCount >> start >> finish))
        return 0;

    vector<vector<pair<int, int>>> graph(vertexCount), graphR(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graphR[b].push_back({ a, w });
    }

    vector<int> distStart = dijkstra(graph, start);
    vector<int> distFinish = dijkstra(graphR, finish);

    vector<vector<pair<int, int>>> graph2(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        for (auto &[to, w] : graph[v])
            if (distStart[v] + w + distFinish[to] != distStart[finish])
                graph2[v].push_back({ to, w });

    vector<int> dist2 = dijkstra(graph2, start);

    cout << (dist2[finish] != 1e9 ? dist2[finish] : -1) << "\n";
    return 1;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}