#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    int res = 1;
    for (int to : graph[v])
        if (!visited[to])
            res += dfs(graph, to, visited);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;
    vertexCount++;

    vector<vector<int>> graph(vertexCount);
    for (int v = 1; v < vertexCount; v++) {
        int from;
        cin >> from;
        graph[from].push_back(v);
    }

    int visitedCount;
    cin >> visitedCount;

    vector<int> visited(vertexCount);
    for (int i = 0; i < visitedCount; i++) {
        int v;
        cin >> v;
        visited[v] = 1;
    }

    cout << dfs(graph, 0, visited) - 1;
}