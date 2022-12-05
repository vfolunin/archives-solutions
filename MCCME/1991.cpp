#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> g, gr;
    vector<int> visited;
    vector<int> order;
    vector<int> scc;

    Graph(int vertexCount) {
        g.resize(vertexCount);
        gr.resize(vertexCount);
        visited.resize(vertexCount);
        scc.resize(vertexCount);
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

    void dfs2(int v, int component) {
        visited[v] = 1;
        scc[v] = component;
        for (int to : gr[v]) {
            if (!visited[to])
                dfs2(to, component);
        }
    }

    vector<int> condense() {
        for (int v = 0; v < g.size(); v++)
            if (!visited[v])
                dfs1(v);
        reverse(order.begin(), order.end());

        visited.assign(g.size(), 0);
        int sccCount = 0;
        for (int v : order)
            if (!visited[v])
                dfs2(v, ++sccCount);

        return scc;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    vector<int> scc = graph.condense();

    cout << *max_element(scc.begin(), scc.end()) << "\n";
    for (int c : scc)
        cout << c << " ";
}