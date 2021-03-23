#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order, bool &cycle) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (!visited[to])
            dfs(graph, to, visited, order, cycle);
        else if (visited[to] == 1)
            cycle = 1;
    }
    visited[v] = 2;
    order.push_back(v);
}

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    vector<int> visited(vertexCount), order;
    bool cycle = 0;
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, visited, order, cycle);
    reverse(order.begin(), order.end());

    if (cycle) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int v : order)
            cout << v + 1 << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}