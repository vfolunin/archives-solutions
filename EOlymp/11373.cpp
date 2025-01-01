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

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        int to = ((v + 1) * 2 - 1) % vertexCount;
        graph[v].push_back(to);
        graph[to].push_back(v);
    }

    vector<int> visited(vertexCount);
    dfs(graph, 0, visited);

    if (auto it = find(visited.begin(), visited.end(), 0); it != visited.end())
        cout << "NO\n1 " << it - visited.begin() + 1 << "\n";
    else
        cout << "YES\n";
}