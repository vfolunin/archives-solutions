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

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color, bool &isBipartite) {
    visited[v] = color;
    for (int to : graph[v]) {
        if (visited[to] == 0)
            dfs(graph, to, visited, 3 - color, isBipartite);
        else if (visited[to] == color)
            isBipartite = 0;
    }
}

bool can(int vertexCount, vector<Edge> &edges, int threshold) {
    vector<vector<int>> graph(vertexCount);
    for (auto &[a, b, weight] : edges) {
        if (weight <= threshold) {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }

    vector<int> visited(vertexCount);
    bool isBipartite = 1;
    for (int v = 0; v < vertexCount && isBipartite; v++)
        if (!visited[v])
            dfs(graph, v, visited, 1, isBipartite);
    return isBipartite;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, weight] : edges) {
        cin >> a >> b >> weight;
        a--;
        b--;
    }

    int l = -1, r = 1e5 + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(vertexCount, edges, m))
            l = m;
        else
            r = m;
    }

    cout << r;
}