#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph;
    vector<int> visited, depth, upDepth;
    set<pair<int, int>> bridges;
    int bccCount = 1;

    void dfs1(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];

        for (int to : graph[v]) {
            if (to == p) {
                continue;
            } else if (!visited[to]) {
                dfs1(to, v);
                upDepth[v] = min(upDepth[v], upDepth[to]);
                if (upDepth[to] > depth[v])
                    bridges.insert({ v, to });
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }
    }

    void dfs2(int v, int color) {
        visited[v] = color;

        for (int to : graph[v]) {
            if (visited[to] == -1) {
                if (bridges.count({ v, to }) || bridges.count({ to, v })) {
                    bccCount++;
                    dfs2(to, bccCount - 1);
                } else {
                    dfs2(to, color);
                }
            }
        }
    }

    Graph(int vertexCount) :
        graph(vertexCount), visited(vertexCount), depth(vertexCount), upDepth(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void condense() {
        dfs1(0, -1);
        visited.assign(graph.size(), -1);
        dfs2(0, 0);
    }
};

struct GraphLCA {
    vector<vector<int>> graph, ancestor;
    vector<int> l, r, depth;
    int timer = 0;

    GraphLCA(int vertexCount) :
        graph(vertexCount),
        ancestor(vertexCount, vector<int>(20)),
        l(vertexCount),
        r(vertexCount),
        depth(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void dfs(int v, int parent) {
        depth[v] = (v == parent ? 0 : depth[parent] + 1);
        l[v] = timer++;

        ancestor[v][0] = parent;
        for (int i = 1; i < ancestor[v].size(); i++)
            ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];

        for (int to : graph[v])
            if (to != parent)
                dfs(to, v);

        r[v] = timer++;
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

        for (int i = ancestor[a].size() - 1; i >= 0; i--)
            if (!isAncestor(ancestor[a][i], b))
                a = ancestor[a][i];

        return ancestor[a][0];
    }

    int lcaDepth(int a, int b) {
        return depth[lca(a, b)];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int vertexCount, edgeCount, root;
    cin >> vertexCount >> edgeCount >> root;
    root--;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph.addEdge(a, b);
    }

    graph.condense();
    GraphLCA bccGraph(graph.bccCount);
    for (auto &[a, b] : graph.bridges)
        bccGraph.addEdge(graph.visited[a], graph.visited[b]);
    bccGraph.prepare(graph.visited[root]);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        cout << bccGraph.lcaDepth(graph.visited[a], graph.visited[b]) << "\n";
    }
}