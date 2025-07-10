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
    set<int> cutpoints;

    void dfs(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];
        int childrenCount = 0;

        for (int to : graph[v]) {
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

    Graph(int vertexCount) :
        graph(vertexCount), visited(vertexCount), depth(vertexCount), upDepth(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    set<int> getCutpoints() {
        for (int v = 0; v < graph.size(); v++)
            if (!visited[v])
                dfs(v, -1);
        return cutpoints;
    }
};

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    set<int> cutpoints = graph.getCutpoints();

    cout << "Case " << test << ": " << cutpoints.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}