#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> g, gR;
    vector<int> visited, order, sccIndex;
    int vertexCount, sccCount;

    Graph(int vertexCount) : vertexCount(vertexCount) {
        g.resize(vertexCount);
        gR.resize(vertexCount);
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
        gR[b].push_back(a);
    }

    void dfs1(int v) {
        visited[v] = 1;
        for (int to : g[v])
            if (!visited[to])
                dfs1(to);
        order.push_back(v);
    }

    void dfs2(int v, int scc) {
        visited[v] = 1;
        sccIndex[v] = scc;
        for (int to : gR[v])
            if (!visited[to])
                dfs2(to, scc);
    }

    int makeScc() {
        visited.assign(vertexCount, 0);
        order.clear();

        for (int v = 0; v < vertexCount; v++)
            if (!visited[v])
                dfs1(v);

        reverse(order.begin(), order.end());
        visited.assign(vertexCount, 0);
        sccIndex.assign(vertexCount, 0);
        sccCount = 0;

        for (int v : order)
            if (!visited[v])
                dfs2(v, sccCount++);

        vector<int> isSource(sccCount, 1);

        for (int v = 0; v < vertexCount; v++)
            for (int to : g[v])
                if (sccIndex[v] != sccIndex[to])
                    isSource[sccIndex[to]] = 0;

        return count(isSource.begin(), isSource.end(), 1);
    }
};

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    cout << "Case " << test << ": " << graph.makeScc() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}