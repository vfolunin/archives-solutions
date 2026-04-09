#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<pair<int, int>>> graph;
    vector<int> visited, depth, upDepth, bridges;

    void dfs(int v, int parent, int pIndex) {
        visited[v] = 1;
        depth[v] = (pIndex == -1 ? 0 : depth[parent] + 1);
        upDepth[v] = depth[v];

        for (auto &[to, index] : graph[v]) {
            if (index == pIndex) {
                continue;
            } else if (!visited[to]) {
                dfs(to, v, index);
                upDepth[v] = min(upDepth[v], upDepth[to]);
                if (upDepth[to] > depth[v])
                    bridges.push_back(index);
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }
    }

    Graph(int vertexCount) :
        graph(vertexCount), visited(vertexCount), depth(vertexCount), upDepth(vertexCount) {}

    void addEdge(int a, int b, int index) {
        graph[a].push_back({ b, index });
        graph[b].push_back({ a, index });
    }

    vector<int> getBridges() {
        for (int v = 0; v < graph.size(); v++)
            if (!visited[v])
                dfs(v, -1, -1);
        sort(bridges.begin(), bridges.end());
        return bridges;
    }
};

int main() {
    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1, i);
    }

    vector<int> bridges = graph.getBridges();

    cout << bridges.size() << "\n";
    for (int index : bridges)
        cout << index + 1 << " ";
}