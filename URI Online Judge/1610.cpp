#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int &cycle) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (!visited[to]) {
            dfs(graph, to, visited, cycle);
        } else if (visited[to] == 1) {
            cycle = 1;
            return;
        }
    }
    visited[v] = 2;
}

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    
    vector<int> visited(vertexCount);
    int cycle = 0;

    for (int v = 0; !cycle && v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, visited, cycle);
    
    cout << (cycle ? "SIM\n" : "NAO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}