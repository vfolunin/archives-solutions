#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, bool &hasCycle) {
    visited[v] = 1;

    for (int to : graph[v]) {
        if (visited[to] == 0)
            dfs(graph, to, visited, hasCycle);
        else if (visited[to] == 1)
            hasCycle = 1;
    }

    visited[v] = 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;
            if (hasEdge)
                graph[a].push_back(b);
        }
    }

    vector<int> visited(vertexCount);
    bool hasCycle = 0;
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, visited, hasCycle);

    cout << hasCycle;
}