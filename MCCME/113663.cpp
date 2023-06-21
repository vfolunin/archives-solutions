#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int dfs(unordered_map<int, unordered_set<int>> &graph, int v) {
    int res = 1;
    for (int to : graph[v])
        res = max(res, 1 + dfs(graph, to));
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < vertexCount; i++) {
        int v, from;
        cin >> v >> from;
        graph[v];
        if (from)
            graph[from].insert(v);
    }

    int res = 0;
    for (auto &[v, adj] : graph)
        res = max(res, dfs(graph, v));

    cout << res;
}