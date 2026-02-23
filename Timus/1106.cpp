#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color) {
    visited[v] = color;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, 3 - color);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        for (int to; cin >> to && to; )
            graph[v].push_back(to - 1);
    
    vector<int> visited(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, visited, 1);

    vector<int> res;
    for (int v = 0; v < vertexCount; v++)
        if (visited[v] == 1)
            res.push_back(v);

    cout << res.size() << "\n";
    for (int v : res)
        cout << v + 1 << " ";
}