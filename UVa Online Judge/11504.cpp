#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs1(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs1(graph, to, visited, order);
    order.push_back(v);
}

void dfs2(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs2(graph, to, visited);
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

    vector<int> visited(vertexCount), order;
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            dfs1(graph, v, visited, order);
    reverse(order.begin(), order.end());

    int res = 0;

    fill(visited.begin(), visited.end(), 0);
    for (int v : order) {
        if (!visited[v]) {
            res++;
            dfs2(graph, v, visited);
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}