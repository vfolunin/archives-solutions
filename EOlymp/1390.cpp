#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int from, vector<int> &visited, bool &hasCycle) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (visited[to] == 0) {
            dfs(graph, to, v, visited, hasCycle);
        } else if (visited[to] == 1 && to != from) {
            hasCycle = 1;
        }
    }
    visited[v] = 2;
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
    bool hasCycle = 0;
    for (int v = 0; !hasCycle && v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, -1, visited, hasCycle);

    cout << (hasCycle ? "YES" : "NO");
}