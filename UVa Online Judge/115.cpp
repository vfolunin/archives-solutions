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
    int timer = 0;

    Graph(int vertexCount) :
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
        if (!isAncestor(ancestor[a][0], b))
            return -1;
        return ancestor[a][0];
    }

    int distance(int a, int b) {
        return abs(depth[a] - depth[b]);
    }
};

int getId(map<string, int> &vertexId, string &name) {
    if (!vertexId.count(name))
        vertexId[name] = vertexId.size();
    return vertexId[name];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, int> vertexId;
    Graph graph(301);

    set<int> ids, cantBeRoot;

    while (1) {
        string a, b;
        cin >> a >> b;

        if (a == "no.child")
            break;

        int va = getId(vertexId, a);
        int vb = getId(vertexId, b);

        graph.addEdge(va, vb);
        ids.insert(va);
        ids.insert(vb);
        cantBeRoot.insert(va);
    }

    for (int v : ids)
        if (!cantBeRoot.count(v))
            graph.prepare(v);

    while (1) {
        string a, b;
        if (!(cin >> a >> b))
            break;

        int va = getId(vertexId, a);
        int vb = getId(vertexId, b);

        if (va == vb || !ids.count(va) || !ids.count(vb)) {
            cout << "no relation\n";

        } else if (graph.isAncestor(va, vb)) {
            int d = graph.distance(va, vb);
            for (int i = 2; i < d; i++)
                cout << "great ";
            if (d > 1)
                cout << "grand ";
            cout << "parent\n";

        } else if (graph.isAncestor(vb, va)) {
            int d = graph.distance(va, vb);
            for (int i = 2; i < d; i++)
                cout << "great ";
            if (d > 1)
                cout << "grand ";
            cout << "child\n";

        } else if (int vc = graph.lca(va, vb); vc != -1) {
            int da = graph.distance(va, vc);
            int db = graph.distance(vb, vc);
            int d = min(da, db) - 1, r = abs(da - db);
            if (!d && !r) {
                cout << "sibling\n";
            } else {
                cout << d << " cousin";
                if (r)
                    cout << " removed " << r;
                cout << "\n";
            }

        } else {
            cout << "no relation\n";
        }
    }
}