#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph, ancestor;
    vector<int> l, r;
    int timer = 0;

    Graph(int vertexCount) :
        graph(vertexCount),
        ancestor(vertexCount, vector<int>(20)),
        l(vertexCount),
        r(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void dfs(int v, int parent) {
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
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, queryCount;
    cin >> vertexCount >> queryCount;

    Graph graph(vertexCount);

    for (int v = 1; v < vertexCount; v++) {
        int parent;
        cin >> parent;

        graph.addEdge(parent, v);
    }

    graph.prepare(0);

    vector<int> a(queryCount * 2);
    cin >> a[0] >> a[1];

    long long x, y, z;
    cin >> x >> y >> z;

    for (int i = 2; i < a.size(); i++)
        a[i] = (x * a[i - 2] + y * a[i - 1] + z) % vertexCount;

    int v = 0;
    long long res = 0;
    for (int i = 0; i < queryCount; i++) {
        v = graph.lca((a[2 * i] + v) % vertexCount, a[2 * i + 1]);
        res += v;
    }

    cout << res;
}