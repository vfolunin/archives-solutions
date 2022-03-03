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

void solve() {
    int vertexCount, edgeCount, startVertexCount;
    cin >> vertexCount >> edgeCount >> startVertexCount;

    vector<vector<int>> graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    vector<int> visited(vertexCount);

    for (int i = 0; i < startVertexCount; i++) {
        int startVertex;
        cin >> startVertex;
        dfs(graph, startVertex - 1, visited);
    }

    cout << count(visited.begin(), visited.end(), 1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}