#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &graph, int v, vector<int> &dist) {
    dist[v] = 0;
    for (auto [to, weight] : graph[v]) {
        if (dist[to] == -1)
            dfs(graph, to, dist);
        dist[v] = max(dist[v], weight + dist[to]);
    }
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
    }

    vector<int> dist(graph.size(), -1);
    for (int v = 0; v < graph.size(); v++)
        if (dist[v] == -1)
            dfs(graph, v, dist);

    cout << *max_element(dist.begin(), dist.end());
}