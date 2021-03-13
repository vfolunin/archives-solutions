#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> g, gR;
    vector<int> visited, order, sccIndex, sccSize, sccDescCount;
    int vertexCount, sccCount;
    vector<set<int>> gScc;

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

    void dfs3(int v) {
        visited[v] = 1;
        sccDescCount[v] = sccSize[v];
        for (int to : gScc[v]) {
            if (!visited[to])
                dfs3(to);
            sccDescCount[v] += sccDescCount[to];
        }
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

        sccSize.resize(sccCount);
        for (int v = 0; v < vertexCount; v++)
            sccSize[sccIndex[v]]++;

        gScc.resize(sccCount);
        for (int v = 0; v < vertexCount; v++)
            for (int to : g[v])
                if (sccIndex[v] != sccIndex[to])
                    gScc[sccIndex[v]].insert(sccIndex[to]);

        sccDescCount.resize(sccCount);
        visited.assign(sccCount, 0);
        for (int v = 0; v < sccCount; v++)
            if (!visited[v])
                dfs3(v);

        int res = 0;
        for (int v = 1; v < vertexCount; v++)
            if (sccDescCount[sccIndex[v]] > sccDescCount[sccIndex[res]])
                res = v;

        return res;
    }
};

void solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    Graph graph(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    cout << "Case " << test << ": " << graph.makeScc() + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}