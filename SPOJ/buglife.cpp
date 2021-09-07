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
        if (visited[to] == color)
            return 0;
        if (!visited[to] && !dfs(graph, to, visited, 3 - color))
            return 0;
    }
    return 1;
}

void solve(int test) {
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

    cout << "Scenario #" << test << ":\n";

    vector<int> visited(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v] && !dfs(graph, v, visited, 1)) {
            cout << "Suspicious bugs found!\n";
            return;
        }
    }

    cout << "No suspicious bugs found!\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}