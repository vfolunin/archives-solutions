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
    vector<vector<long long>> sumWeight;
    vector<int> l, r;
    int timer;

    Graph(int vertexCount) :
        graph(vertexCount),
        ancestor(vertexCount),
        sumWeight(vertexCount),
        l(vertexCount),
        r(vertexCount) {}

    void addEdge(int a, int b, int w) {
        graph[a][b] = w;
        graph[b][a] = w;
    }

    void dfs(int v, int parent) {
        l[v] = ++timer;

        ancestor[v].push_back(parent);
        sumWeight[v].push_back(v == parent ? 0 : graph[v][parent]);

        for (int i = 1; i < 20; i++) {
            ancestor[v].push_back(ancestor[ancestor[v][i - 1]][i - 1]);
            sumWeight[v].push_back(sumWeight[v].back() + sumWeight[ancestor[v][i - 1]][i - 1]);
        }

        for (auto &[to, _] : graph[v])
            if (!l[to])
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
        for (int i = 19; i >= 0; i--)
            if (!isAncestor(ancestor[a][i], b))
                a = ancestor[a][i];
        return ancestor[a][0];
    }

    long long sumWeightOnPathToLca(int a, int b) {
        long long res = 0;
        for (int i = 19; i >= 0; i--) {
            if (isAncestor(a, ancestor[b][i])) {
                res += sumWeight[b][i];
                b = ancestor[b][i];
            }
        }
        return res;
    }

    long long sumWeightOnPath(int a, int b) {
        int l = lca(a, b);
        long long sa = sumWeightOnPathToLca(l, a);
        long long sb = sumWeightOnPathToLca(l, b);
        return sa + sb;
    }
};

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    Graph graph(vertexCount);
    for (int v = 1; v < vertexCount; v++) {
        int p, w;
        cin >> p >> w;
        graph.addEdge(p, v, w);
    }

    graph.prepare(0);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        cout << graph.sumWeightOnPath(a, b) << (i + 1 < queryCount ? " " : "\n");
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}