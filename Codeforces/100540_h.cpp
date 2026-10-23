#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> g;
    vector<int> visited, depth, upDepth;
    vector<pair<int, int>> bridges;

    void dfs(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];

        for (int to : g[v]) {
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

    Graph(int vertexCount) {
        g.resize(vertexCount);
        visited.resize(vertexCount);
        depth.resize(vertexCount);
        upDepth.resize(vertexCount);
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<pair<int, int>> getBridges() {
        for (int v = 0; v < g.size(); v++)
            if (!visited[v])
                dfs(v, -1);
        return bridges;
    }
};

struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

bool solve() {
    int vertexCount, edgeCount, queryCount;
    cin >> vertexCount >> edgeCount >> queryCount;

    if (!vertexCount)
        return 0;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    DSU dsu(vertexCount);
    for (auto &[a, b] : graph.getBridges())
        dsu.merge(a, b);

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        cout << (dsu.connected(a - 1, b - 1) ? "Y\n" : "N\n");
    }
    cout << "-\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}