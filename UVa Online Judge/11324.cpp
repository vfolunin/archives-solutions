#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    int vertexCount, sccCount;
    map<int, set<int>> g, gr, gc;
    set<int> visited;
    vector<int> order;
    map<int, int> sccIndexOf, sccSize, pathSize;

    Graph(int vertexCount) : vertexCount(vertexCount), sccCount(0) {}

    void addEdge(int a, int b) {
        g[a].insert(b);
        gr[b].insert(a);
    }

    void dfs1(map<int, set<int>> &g, int v) {
        visited.insert(v);
        for (int to : g[v])
            if (!visited.count(to))
                dfs1(g, to);
        order.push_back(v);
    }

    void dfs2(int v, int component) {
        visited.insert(v);
        sccIndexOf[v] = component;
        sccSize[component]++;
        for (int to : gr[v]) {
            if (!visited.count(to))
                dfs2(to, component);
        }
    }

    void condense() {
        for (int v = 0; v < vertexCount; v++)
            if (!visited.count(v))
                dfs1(g, v);
        reverse(order.begin(), order.end());

        visited.clear();
        for (int v : order)
            if (!visited.count(v))
                dfs2(v, sccCount++);

        for (int v = 0; v < vertexCount; v++)
            for (int to : g[v])
                if (sccIndexOf[v] != sccIndexOf[to])
                    gc[sccIndexOf[v]].insert(sccIndexOf[to]);
    }

    int dfs3(int v) {
        pathSize[v] = sccSize[v];
        for (int to : gc[v]) {
            if (!pathSize.count(to))
                pathSize[v] = max(pathSize[v], sccSize[v] + dfs3(to));
            else
                pathSize[v] = max(pathSize[v], sccSize[v] + pathSize[to]);
        }
        return pathSize[v];
    }

    int getPathSize() {
        order.clear();
        visited.clear();
        for (int v = 0; v < sccCount; v++)
            if (!visited.count(v))
                dfs1(gc, v);
        reverse(order.begin(), order.end());

        int res = 0;
        for (int v = 0; v < sccCount; v++)
            if (!pathSize.count(v))
                res = max(res, dfs3(v));
        return res;
    }
};

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    graph.condense();
    cout << graph.getPathSize() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}