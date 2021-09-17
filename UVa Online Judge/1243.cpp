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
    map<int, int> sccIndexOf, sccSize;

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
        sccSize[component]++;
        for (int to : gr[v]) {
            if (!visited.count(to))
                dfs2(to, component);
        }
    }

    int condense() {
        for (int v = 0; v < vertexCount; v++)
            if (!visited.count(v))
                dfs1(v);
        reverse(order.begin(), order.end());

        visited.clear();
        for (int v : order)
            if (!visited.count(v))
                dfs2(v, sccCount++);

        vector<vector<int>> hasEdge(sccCount, vector<int>(sccCount));

        for (int v = 0; v < vertexCount; v++)
            for (int to : g[v])
                if (sccIndexOf[v] != sccIndexOf[to])
                    hasEdge[sccIndexOf[v]][sccIndexOf[to]] = 1;

        for (int v = 0; v < sccCount; v++)
            for (int a = 0; a < sccCount; a++)
                for (int b = 0; b < sccCount; b++)
                    if (hasEdge[a][v] && hasEdge[v][b])
                        hasEdge[a][b] = 1;

        for (int v = 0; v < sccCount; v++)
            for (int a = 0; a < sccCount; a++)
                for (int b = 0; b < sccCount; b++)
                    if (hasEdge[a][v] && hasEdge[v][b])
                        hasEdge[a][b] = 0;

        int res = 0;
        for (int v = 0; v < sccCount; v++)
            for (int to = 0; to < sccCount; to++)
                res += hasEdge[v][to];

        for (auto &[_, size] : sccSize)
            if (size > 1)
                res += size;

        return res;
    }
};

bool solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;
    
    if (!vertexCount)
        return 0;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    int res = graph.condense();

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}