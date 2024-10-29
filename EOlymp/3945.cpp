#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<map<int, int>> graph;
    vector<vector<int>> ancestor;
    vector<int> l, r, depth, red, blue;
    int timer = 0;

    Graph(int vertexCount) :
        graph(vertexCount),
        ancestor(vertexCount),
        depth(vertexCount),
        l(vertexCount),
        r(vertexCount),
        red(vertexCount),
        blue(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a][b] = 0;
        graph[b][a] = 1;
    }

    void dfs(int v, int parent) {
        l[v] = ++timer;
        depth[v] = (v == parent ? 0 : depth[parent] + 1);

        ancestor[v].push_back(parent);
        if (v != parent) {
            if (!graph[v][parent])
                red[v] = red[parent] + 1;
            else
                blue[v] = blue[parent] + 1;
        }

        for (int i = 1; i < 20; i++)
            ancestor[v].push_back(ancestor[ancestor[v][i - 1]][i - 1]);

        for (auto &[to, _] : graph[v])
            if (!l[to])
                dfs(to, v);

        r[v] = ++timer;
    }

    void prepare(int root) {
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

        for (int i = 19; i >= 0; i--)
            if (!isAncestor(ancestor[a][i], b))
                a = ancestor[a][i];

        return ancestor[a][0];
    }

    bool can(int a, int b) {
        int l = lca(a, b);

        if (red[a] < depth[a] - depth[l])
            return 0;

        if (blue[b] < depth[b] - depth[l])
            return 0;

        return 1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    Graph graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    graph.prepare(0);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        cout << (graph.can(a - 1, b - 1) ? "Yes\n" : "No\n");
    }
}