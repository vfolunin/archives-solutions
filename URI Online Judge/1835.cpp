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

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    vector<int> visited(vertexCount);
    int ccCount = 0;

    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v]) {
            dfs(graph, v, visited);
            ccCount++;
        }
    }

    cout << "Caso #" << test << ": ";
    if (ccCount == 1)
        cout << "a promessa foi cumprida\n";
    else
        cout << "ainda falta(m) " << ccCount - 1 << " estrada(s)\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}