#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, w;

    bool operator < (const Edge &that) const {
        return w > that.w;
    }
};

int dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    int res = 1;
    for (int to : graph[v])
        if (!visited[to])
            res += dfs(graph, to, visited);
    return res;
}

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges) {
        cin >> a >> b >> w;
        a--;
        b--;
    }

    vector<vector<int>> graph(vertexCount);
    sort(edges.begin(), edges.end());
    for (auto &[a, b, w] : edges) {
        if (w != edges[0].w)
            break;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(vertexCount);
    int res = 0;
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            res = max(res, dfs(graph, v, visited));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}