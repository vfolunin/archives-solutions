#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order) {
    visited[v] = 1;

    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, order);

    order.push_back(v);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<int> cost(vertexCount);
    for (int &c : cost)
        cin >> c;

    vector<vector<int>> graph(vertexCount);

    for (int v = 0; v < vertexCount; v++) {
        int edgeCount;
        cin >> edgeCount;
        for (int i = 0; i < edgeCount; i++) {
            int to;
            cin >> to;
            graph[v].push_back(to - 1);
        }
    }

    vector<int> visited(vertexCount), order;
    dfs(graph, 0, visited, order);

    long long totalCost = 0;
    for (int v : order)
        totalCost += cost[v];

    cout << totalCost << " " << order.size() << "\n";
    for (int v : order)
        cout << v + 1 << " ";
}