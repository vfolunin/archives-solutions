#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &graph, int v, vector<int> &visited, int limit) {
    visited[v] = 1;
    for (auto &[to, weight] : graph[v])
        if (!visited[to] && weight <= limit)
            dfs(graph, to, visited, limit);
}

bool can(vector<vector<pair<int, int>>> &graph, int limit) {
    vector<int> visited(graph.size());
    dfs(graph, 0, visited, limit);
    return visited[graph.size() - 1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;

        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    int l = 0, r = 1;
    while (!can(graph, r))
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(graph, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}