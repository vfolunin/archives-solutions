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
        l[v] = ++timer;

        ancestor[v][0] = parent;
        for (int i = 1; i < ancestor[v].size(); i++)
            ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];

        for (int to : graph[v])
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
        int from;
        cin >> from;
        graph.addEdge(from, v);
    }

    graph.prepare(0);

    vector<long long> a(2 * queryCount);
    long long x, y, z;
    cin >> a[0] >> a[1] >> x >> y >> z;

    for (int i = 2; i < a.size(); i++)
        a[i] = (a[i - 2] * x + a[i - 1] * y + z) % vertexCount;

    long long res = 0, resSum = 0;
    for (int i = 0; i < queryCount; i++) {
        res = graph.lca((a[2 * i] + res) % vertexCount, a[2 * i + 1]);
        resSum += res;
    }

    cout << resSum;
}