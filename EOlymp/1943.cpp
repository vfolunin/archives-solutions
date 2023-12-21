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
        int other(int v) {
            return v == a ? b : a;
        }
    };

    vector<Edge> edges;
    vector<vector<int>> g;
    vector<int> visited, depth, upDepth, bridges;

    void dfs(int v, int parentEdge) {
        visited[v] = 1;
        depth[v] = (parentEdge == -1 ? 0 : depth[edges[parentEdge].other(v)] + 1);
        upDepth[v] = depth[v];

        for (int edgeIndex : g[v]) {
            int to = edges[edgeIndex].other(v);
            if (edgeIndex == parentEdge) {
                continue;
            } else if (!visited[to]) {
                dfs(to, edgeIndex);
                upDepth[v] = min(upDepth[v], upDepth[to]);
                if (upDepth[to] > depth[v])
                    bridges.push_back(edgeIndex);
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }
    }

    Graph(int vertexCount) {
        g.resize(vertexCount);
        visited.resize(vertexCount);
        depth.resize(vertexCount);
        upDepth.resize(vertexCount);
    }

    void addEdge(int a, int b) {
        edges.push_back({ a, b });
        g[a].push_back(edges.size() - 1);
        g[b].push_back(edges.size() - 1);
    }

    vector<int> getBridges() {
        for (int v = 0; v < g.size(); v++)
            if (!visited[v])
                dfs(v, -1);
        sort(bridges.begin(), bridges.end());
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
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    vector<int> bridges = graph.getBridges();

    cout << bridges.size() << "\n";
    for (int b : bridges)
        cout << b + 1 << " ";
}