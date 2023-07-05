#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<pair<int, int>>> graph;
    vector<int> visited, depth, upDepth;
    int ccCount = 1;
    vector<int> ccOf, ccSize, ccDegree;

    void dfs1(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];

        for (auto &[to, bridge] : graph[v]) {
            if (to == p) {
                continue;
            } else if (!visited[to]) {
                dfs1(to, v);
                upDepth[v] = min(upDepth[v], upDepth[to]);
                bridge = upDepth[to] > depth[v];
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }
    }

    void dfs2(int v, int component) {
        ccOf[v] = component;
        ccSize[component]++;

        for (auto &[to, bridge] : graph[v]) {
            if (ccOf[to] == -1)
                dfs2(to, bridge ? ccCount++ : component);
            ccDegree[component] += ccOf[v] != ccOf[to];
        }
    }

    Graph(int vertexCount) :
        graph(vertexCount), visited(vertexCount), depth(vertexCount), upDepth(vertexCount),
        ccOf(vertexCount, -1), ccSize(vertexCount), ccDegree(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back({ b, 0 });
        graph[b].push_back({ a, 0 });
    }

    pair<int, int> getLeafCcStats() {
        dfs1(0, -1);
        dfs2(0, 0);

        int leafCcCount = 0;
        long long ways = 1, MOD = 1e9 + 7;
        for (int cc = 0; cc < ccCount; cc++) {
            if (ccDegree[cc] <= 1) {
                leafCcCount++;
                ways = ways * ccSize[cc] % MOD;
            }
        }
        return { leafCcCount, ways };
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

    auto [leafCcCount, ways] = graph.getLeafCcStats();
    cout << leafCcCount << " " << ways;
}