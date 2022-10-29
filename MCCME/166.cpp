#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order, bool &hasCycle) {
    visited[v] = 1;

    for (int to : graph[v]) {
        if (visited[to] == 0)
            dfs(graph, to, visited, order, hasCycle);
        else if (visited[to] == 1)
            hasCycle = 1;
    }

    order.push_back(v);
    visited[v] = 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    vector<int> visited(vertexCount), order;
    bool hasCycle = 0;
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, visited, order, hasCycle);
    reverse(order.begin(), order.end());

    if (!hasCycle) {
        cout << "Yes\n";
        for (int v : order)
            cout << v + 1 << " ";
    } else {
        cout << "No\n";
    }
}