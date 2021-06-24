#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    struct Edge {
        int a, b, orientation;
        int other(int v) {
            return v == a ? b : a;
        }
    };

    vector<Edge> edges;
    vector<vector<int>> g;
    vector<int> visited, depth, upDepth;

    void dfs(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];

        for (int ei : g[v]) {
            int to = edges[ei].other(v);
            if (to == p) {
                continue;
            } else if (!visited[to]) {
                dfs(to, v);
                upDepth[v] = min(upDepth[v], upDepth[to]);
                if (upDepth[to] > depth[v])
                    edges[ei].orientation = 3;
                else
                    edges[ei].orientation = (v == edges[ei].a ? 1 : 2);
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
                edges[ei].orientation = (v == edges[ei].a ? 2 : 1);
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
        edges.push_back({ a, b, 0 });
        g[a].push_back(edges.size() - 1);
        g[b].push_back(edges.size() - 1);
    }

    void orient() {
        dfs(0, -1);
    }
};

bool solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount)
        return 0;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    graph.orient();

    cout << test << "\n\n";
    for (auto &[a, b, orientation] : graph.edges) {
        if (orientation & 1)
            cout << a + 1 << " " << b + 1 << "\n";
        if (orientation & 2)
            cout << b + 1 << " " << a + 1 << "\n";
    }
    cout << "#\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}