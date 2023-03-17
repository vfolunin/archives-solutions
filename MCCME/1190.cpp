#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    struct Edge {
        int a, b;
        bool directed = 0;
        int other(int v) {
            return v == a ? b : a;
        }
    };
    vector<Edge> edges;
    vector<vector<int>> graph;
    vector<int> visited, depth, upDepth;
    bool hasBridge = 0;

    void dfs(int v, int parentEdge) {
        visited[v] = 1;
        depth[v] = (parentEdge == -1 ? 0 : depth[edges[parentEdge].other(v)] + 1);
        upDepth[v] = depth[v];

        for (int edgeIndex : graph[v]) {
            int to = edges[edgeIndex].other(v);
            if (!edges[edgeIndex].directed)
                edges[edgeIndex] = { v, to, 1 };
            if (edgeIndex == parentEdge) {
                continue;
            } else if (!visited[to]) {
                dfs(to, edgeIndex);
                upDepth[v] = min(upDepth[v], upDepth[to]);
                if (upDepth[to] > depth[v])
                    hasBridge = 1;
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }
    }

    Graph(int vertexCount) :
        graph(vertexCount), visited(vertexCount), depth(vertexCount), upDepth(vertexCount) {}

    void addEdge(int a, int b) {
        edges.push_back({ a, b });
        graph[a].push_back(edges.size() - 1);
        graph[b].push_back(edges.size() - 1);
    }

    bool directEdges() {
        dfs(0, -1);
        return !hasBridge;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    if (graph.directEdges()) {
        for (auto &[a, b, _] : graph.edges)
            cout << a + 1 << " " << b + 1 << "\n";
    } else {
        cout << 0;
    }
}