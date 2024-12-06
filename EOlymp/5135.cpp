#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
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

    vector<int> visited(vertexCount);
    vector<pair<int, int>> res;
    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v]) {
            dfs(graph, v, visited);
            if (v)
                res.push_back({ 0, v });
        }
    }

    cout << res.size() << "\n";
    for (auto &[a, b] : res)
        cout << a + 1 << " " << b + 1 << "\n";
}