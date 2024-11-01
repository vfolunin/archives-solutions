#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> g, gr;
    vector<int> visited, order;

    Graph(int vertexCount) {
        g.resize(vertexCount);
        gr.resize(vertexCount);
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    void dfs1(int v) {
        visited[v] = 1;
        for (int to : g[v])
            if (!visited[to])
                dfs1(to);
        order.push_back(v);
    }

    void dfs2(int v) {
        visited[v] = 1;
        for (int to : gr[v])
            if (!visited[to])
                dfs2(to);
    }

    bool isStronglyConnected() {
        visited.assign(g.size(), 0);
        for (int v = 0; v < g.size(); v++)
            if (!visited[v])
                dfs1(v);

        visited.assign(g.size(), 0);
        dfs2(order.back());
        return !count(visited.begin(), visited.end(), 0);
    }
};

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, type;
        cin >> a >> b >> type;
        graph.addEdge(a - 1, b - 1);
        if (type == 2)
            graph.addEdge(b - 1, a - 1);
    }

    cout << (graph.isStronglyConnected() ? "1\n" : "0\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    while (solve());
}