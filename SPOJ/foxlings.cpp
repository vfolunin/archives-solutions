#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

int getId(unordered_map<int, int> &id, int v) {
    if (!id.count(v))
        id[v] = id.size();
    return id[v];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<pair<int, int>> edges(edgeCount);
    unordered_map<int, int> id;

    for (auto &[a, b] : edges) {
        cin >> a >> b;

        a = getId(id, a);
        b = getId(id, b);
    }

    vector<vector<int>> graph(id.size());
    for (auto &[a, b] : edges) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(graph.size());
    int ccCount = vertexCount - graph.size();
    for (int v = 0; v < graph.size(); v++) {
        if (!visited[v]) {
            dfs(graph, v, visited);
            ccCount++;
        }
    }

    cout << ccCount;
}