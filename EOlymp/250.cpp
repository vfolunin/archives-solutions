#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<pair<int, int>>> graph;
    vector<int> visited, depth, upDepth;
    vector<pair<int, int>> bridges;

    void dfs(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];

        for (auto &[to, _] : graph[v]) {
            if (to == p) {
                continue;
            } else if (!visited[to]) {
                dfs(to, v);
                upDepth[v] = min(upDepth[v], upDepth[to]);
                if (upDepth[to] > depth[v])
                    bridges.push_back({ v, to });
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }
    }

    Graph(int vertexCount) :
        graph(vertexCount), visited(vertexCount), depth(vertexCount), upDepth(vertexCount) {}

    void addEdge(int a, int b, int weight) {
        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    vector<int> dijkstra(int start) {
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

    vector<pair<int, int>> getBridges() {
        for (int v = 0; v < graph.size(); v++)
            if (!visited[v])
                dfs(v, -1);
        return bridges;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        graph.addEdge(a - 1, b - 1, weight);
    }

    int startA, startB;
    cin >> startA >> startB;

    vector<int> distA = graph.dijkstra(startA - 1);
    vector<int> distB = graph.dijkstra(startB - 1);

    int res = 1e9;
    for (auto &[a, b] : graph.getBridges())
        res = min({ res, max(distA[a], distB[b]), max(distA[b], distB[a]) });

    cout << res;
}