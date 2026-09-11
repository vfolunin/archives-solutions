#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    int res = 1;
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            res += dfs(graph, to, visited);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(graph.size());
    int res = 0;
    for (int v = 0; v < graph.size(); v++)
        if (!visited[v])
            res = max(res, dfs(graph, v, visited));

    cout << res;
}