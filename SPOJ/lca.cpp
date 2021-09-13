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

void solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    Graph graph(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        int degree;
        cin >> degree;
        for (int i = 0; i < degree; i++) {
            int to;
            cin >> to;
            graph.addEdge(v, to - 1);
        }
    }

    graph.prepare(0);

    int queryCount;
    cin >> queryCount;

    cout << "Case " << test << ":\n";
    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        cout << graph.lca(a - 1, b - 1) + 1 << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}