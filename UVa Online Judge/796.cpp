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
    vector<pair<int, int>> bridges;

    void dfs(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];

        for (int to : g[v]) {
            if (to == p) {
                continue;
            } else if (!visited[to]) {
                dfs(to, v);
                upDepth[v] = min(upDepth[v], upDepth[to]);
                if (upDepth[to] > depth[v])
                    bridges.push_back({ min(v, to), max(v, to) });
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }
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

    vector<pair<int, int>> getBridges() {
        for (int v = 0; v < g.size(); v++)
            if (!visited[v])
                dfs(v, -1);
        sort(bridges.begin(), bridges.end());
        return bridges;
    }
};

bool solve() {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    Graph graph(vertexCount);
    
    for (int i = 0; i < vertexCount; i++) {
        int v, adjVertexCount;
        char c;
        cin >> v >> c >> adjVertexCount >> c;
        for (int j = 0; j < adjVertexCount; j++) {
            int to;
            cin >> to;
            if (v < to)
                graph.addEdge(v, to);
        }
    }

    vector<pair<int, int>> bridges = graph.getBridges();

    cout << bridges.size() << " critical links\n";
    for (auto &[a, b] : bridges)
        cout << a << " - " << b << "\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}