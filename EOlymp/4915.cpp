#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<pair<int, int>>> graph;
    vector<vector<int>> ancestor;
    vector<int> l, r, depth;
    int timer = 0;

    Graph(int vertexCount) :
        graph(vertexCount),
        ancestor(vertexCount, vector<int>(20)),
        l(vertexCount),
        r(vertexCount),
        depth(vertexCount) {}

    void addEdge(int a, int b, int weight) {
        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    void dfs(int v, int parent) {
        l[v] = timer++;

        ancestor[v][0] = parent;
        for (int i = 1; i < ancestor[v].size(); i++)
            ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];

        for (auto &[to, weight] : graph[v]) {
            if (to != parent) {
                depth[to] = depth[v] + weight;
                dfs(to, v);
            }
        }

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

    int distance(int a, int b) {
        int l = lca(a, b);
        int da = depth[a] - depth[l];
        int db = depth[b] - depth[l];
        return da + db;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int vertexCount;
    cin >> vertexCount;

    Graph graph(vertexCount);

    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;

        graph.addEdge(a, b, weight);
    }

    graph.prepare(0);
    
    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;

        cout << graph.distance(a, b) << "\n";
    }
}