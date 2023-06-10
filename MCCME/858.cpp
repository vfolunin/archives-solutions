#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color) {
    visited[v] = color;
    for (int to : graph[v]) {
        if (!visited[to])
            return dfs(graph, to, visited, color);
        else
            return visited[to] == color;
    }
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        int to;
        cin >> to;
        graph[v].push_back(to - 1);
    }

    vector<int> visited(vertexCount);
    int res = 0;
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            res += dfs(graph, v, visited, v + 1);

    cout << res;
}