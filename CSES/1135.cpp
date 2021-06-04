#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph, up;
    vector<int> l, r, depth;
    int timer;

    Graph(int vertexCount) : graph(vertexCount), up(vertexCount), depth(vertexCount), l(vertexCount), r(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void dfs(int v, int p) {
        depth[v] = (p == v ? 0 : depth[p] + 1);
        l[v] = ++timer;

        up[v].push_back(p);
        for (int i = 1; i < 20; i++)
            up[v].push_back(up[up[v][i - 1]][i - 1]);

        for (int to : graph[v])
            if (to != p)
                dfs(to, v);

        r[v] = ++timer;
    }

    void prepare(int root) {
        timer = 0;
        dfs(root, root);
    }

    bool isAncestor(int a, int b) {
        return l[a] <= l[b] && r[b] <= r[a];
    }

    int lca(int a, int b) {
        if (isAncestor(a, b))
            return a;
        if (isAncestor(b, a))
            return b;
        for (int i = 19; i >= 0; i--) {
            if (!isAncestor(up[a][i], b))
                a = up[a][i];
        }
        return up[a][0];
    }

    int distance(int a, int b) {
        return depth[a] + depth[b] - 2 * depth[lca(a, b)];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, queryCount;
    cin >> vertexCount >> queryCount;

    Graph graph(vertexCount);

    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    graph.prepare(0);

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        cout << graph.distance(a - 1, b - 1) << "\n";
    }
}