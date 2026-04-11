#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph;
    vector<int> visited, depth, upDepth;
    vector<pair<int, int>> bridges;

    void dfs(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];

        for (int to : graph[v]) {
            if (to == p) {
                continue;
            } else if (!visited[to]) {
                dfs(to, v);
                upDepth[v] = min(upDepth[v], upDepth[to]);
                if (upDepth[to] > depth[v])
                    bridges.push_back({ v, to });
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }
    }

    Graph(int vertexCount) :
        graph(vertexCount), visited(vertexCount), depth(vertexCount), upDepth(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<pair<int, int>> getBridges() {
        for (int v = 0; v < graph.size(); v++)
            if (!visited[v])
                dfs(v, -1);
        return bridges;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Graph graph(26);

    for (string s; cin >> s; )
        if (s != "**")
            graph.addEdge(s[0] - 'A', s[1] - 'A');

    vector<pair<int, int>> bridges = graph.getBridges();

    for (auto &[a, b] : bridges)
        cout << (char)(a + 'A') << (char)(b + 'A') << "\n";
    cout << "There are " << bridges.size() << " disconnecting roads.\n";
}