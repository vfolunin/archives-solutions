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

        return sccCount;
    }
};

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;
    cin.ignore();

    if (!vertexCount)
        return 0;

    map<string, int> vertexId;
    for (int i = 0; i < vertexCount; i++) {
        string name;
        getline(cin, name);
        vertexId[name] = i;
    }

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        graph.addEdge(vertexId[a], vertexId[b]);
    }

    cout << graph.makeScc() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}