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

    vector<vector<int>> graph(vertexCount + 50);

    for (int v = 0; v < vertexCount; v++) {
        int degree;
        cin >> degree;

        for (int i = 0; i < degree; i++) {
            int to;
            cin >> to;
            to += vertexCount - 1;

            graph[v].push_back(to);
            graph[to].push_back(v);
        }
    }

    vector<int> visited(graph.size());
    dfs(graph, 0, visited);

    cout << count(visited.begin(), visited.begin() + vertexCount, 1);
}