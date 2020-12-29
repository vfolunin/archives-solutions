#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, order);
    order.push_back(v);
}

bool solve() {
    int n, m;
    cin >> n >> m;
    if (!n && !m)
        return 0;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    vector<int> visited(n), order;
    for (int v = 0; v < n; v++)
        if (!visited[v])
            dfs(graph, v, visited, order);
    reverse(order.begin(), order.end());

    for (int i = 0; i < n; i++)
        cout << order[i] + 1 << (i + 1 < n ? ' ' : '\n');
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}