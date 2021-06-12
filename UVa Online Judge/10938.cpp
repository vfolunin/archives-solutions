#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph, ancestor;
    vector<int> l, r, depth;
    int timer;

    Graph(int vertexCount) :
        graph(vertexCount),
        ancestor(vertexCount),
        l(vertexCount),
        r(vertexCount),
        depth(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void dfs(int v, int parent) {
        depth[v] = (v == parent ? 0 : depth[parent] + 1);
        l[v] = ++timer;

        ancestor[v].push_back(parent);
        for (int i = 1; i < 20; i++)
            ancestor[v].push_back(ancestor[ancestor[v][i - 1]][i - 1]);

        for (int to : graph[v])
            if (!l[to])
                dfs(to, v);

        r[v] = ++timer;
    }

    void prepare() {
        timer = 0;
        dfs(0, 0);
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

    int distance(int a, int b) {
        int l = lca(a, b);
        int da = depth[a] - depth[l];
        int db = depth[b] - depth[l];
        return da + db;
    }

    int kthAncestor(int v, int k) {
        for (int i = 19; i >= 0; i--) {
            if (k >= (1 << i)) {
                k -= 1 << i;
                v = ancestor[v][i];
            }
        }
        return v;
    }
};

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    Graph graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }
    graph.prepare();

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if (graph.depth[a] < graph.depth[b])
            swap(a, b);
        int distance = graph.distance(a, b);

        if (distance % 2 == 0) {
            int r = graph.kthAncestor(a, distance / 2);
            cout << "The fleas meet at " << r + 1 << ".\n";
        } else {
            int ra = graph.kthAncestor(a, distance / 2);
            int rb = graph.kthAncestor(a, distance / 2 + 1);
            if (ra > rb)
                swap(ra, rb);
            cout << "The fleas jump forever between " << ra + 1 << " and " << rb + 1 << ".\n";
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}