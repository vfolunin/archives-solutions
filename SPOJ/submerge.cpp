#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> g;
    vector<int> visited, depth, upDepth;
    set<int> cutpoints;

    void dfs(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];
        int childrenCount = 0;

        for (int to : g[v]) {
            if (to == p) {
                continue;
            } else if (!visited[to]) {
                dfs(to, v);
                childrenCount++;
                upDepth[v] = min(upDepth[v], upDepth[to]);
                if (p != -1 && upDepth[to] >= depth[v])
                    cutpoints.insert(v);
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }

        if (p == -1 && childrenCount > 1)
            cutpoints.insert(v);
    }

    Graph(int vertexCount) {
        g.resize(vertexCount);
        visited.resize(vertexCount);
        depth.resize(vertexCount);
        upDepth.resize(vertexCount);
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    set<int> findCutpoints() {
        for (int v = 0; v < g.size(); v++)
            if (!visited[v])
                dfs(v, -1);
        return cutpoints;
    }
};

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    cout << graph.findCutpoints().size() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}