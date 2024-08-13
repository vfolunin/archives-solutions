#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &delta) {
    visited[v] = 1;
    int res = delta[v];

    for (int to : graph[v])
        if (!visited[to])
            res += dfs(graph, to, visited, delta);

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<int> delta(vertexCount);
    for (int &value : delta)
        cin >> value;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v] && dfs(graph, v, visited, delta)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    cout << "POSSIBLE";
}