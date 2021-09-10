#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, w;
};

bool solve() {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges) {
        cin >> a >> b >> w;
        a--;
        b--;
    }

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;
    for (auto &[a, b, w] : edges)
        dist[a][b] = dist[b][a] = min(dist[a][b], w);

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int resRouteCount = -1;
    vector<int> resEdges;

    for (int i = 0; i < edgeCount; i++) {
        auto [ea, eb, w] = edges[i];

        int routeCount = 0;
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                routeCount += dist[a][ea] + w + dist[eb][b] == dist[a][b] ||
                              dist[a][eb] + w + dist[ea][b] == dist[a][b];

        if (resRouteCount < routeCount) {
            resRouteCount = routeCount;
            resEdges.clear();
        }
        if (resRouteCount == routeCount)
            resEdges.push_back(i);
    }

    for (int i = 0; i < resEdges.size(); i++)
        cout << resEdges[i] + 1 << (i + 1 < resEdges.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}