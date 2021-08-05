#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    int vertexCount, sccCount;
    map<int, set<int>> g, gr;
    set<int> visited;
    vector<int> order;
    map<int, int> sccIndexOf;

    Graph(int vertexCount) : vertexCount(vertexCount), sccCount(0) {}

    void addEdge(int a, int b) {
        g[a].insert(b);
        gr[b].insert(a);
    }

    void dfs1(int v) {
        visited.insert(v);
        for (int to : g[v])
            if (!visited.count(to))
                dfs1(to);
        order.push_back(v);
    }

    void dfs2(int v, int component) {
        visited.insert(v);
        sccIndexOf[v] = component;
        for (int to : gr[v]) {
            if (!visited.count(to))
                dfs2(to, component);
        }
    }

    void condense() {
        for (int v = 0; v < vertexCount; v++)
            if (!visited.count(v))
                dfs1(v);
        reverse(order.begin(), order.end());

        visited.clear();
        for (int v : order)
            if (!visited.count(v))
                dfs2(v, sccCount++);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    graph.condense();

    cout << graph.sccCount << "\n";
    for (int v = 0; v < vertexCount; v++)
        cout << graph.sccIndexOf[v] + 1 << " ";
}