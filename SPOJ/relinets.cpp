#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, weight;
};

struct Graph {
    vector<vector<int>> graph;
    vector<int> visited, depth, upDepth;
    int bridgeCount = 0;

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
                bridgeCount += upDepth[to] > depth[v];
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }
    }

    Graph(int vertexCount, vector<Edge> &edges, int mask) : graph(vertexCount) {
        for (int i = 0; i < edges.size(); i++) {
            if (mask & (1 << i)) {
                graph[edges[i].a].push_back(edges[i].b);
                graph[edges[i].b].push_back(edges[i].a);
            }
        }
    }

    bool isReliable() {
        visited.resize(graph.size());
        depth.resize(graph.size());
        upDepth.resize(graph.size());

        dfs(0, -1);

        return !count(visited.begin(), visited.end(), 0) && !bridgeCount;
    }
};

bool solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, weight] : edges) {
        cin >> a >> b >> weight;
        a--;
        b--;
    }

    int res = 1e9;
    for (int mask = 0; mask < (1 << edgeCount); mask++) {
        int ones = 0, weightSum = 0;
        for (int i = 0; i < edges.size(); i++) {
            if (mask & (1 << i)) {
                ones++;
                weightSum += edges[i].weight;
            }
        }

        if (ones >= vertexCount - 1 && Graph(vertexCount, edges, mask).isReliable())
            res = min(res, weightSum);
    }

    if (res != 1e9)
        cout << "The minimal cost for test case " << test << " is " << res << ".\n";
    else
        cout << "There is no reliable net possible for test case " << test << ".\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}