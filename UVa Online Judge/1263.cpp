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
    int vertexCount;
    cin >> vertexCount;

    vector<int> x(vertexCount), y(vertexCount), r(vertexCount);
    for (int i = 0; i < vertexCount; i++)
        cin >> x[i] >> y[i] >> r[i];

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        for (int j = i + 1; j < vertexCount; j++) {
            if (abs(x[i] - x[j]) * 2 <= r[i] && abs(y[i] - y[j]) * 2 <= r[i])
                graph[i].push_back(j);
            if (abs(x[i] - x[j]) * 2 <= r[j] && abs(y[i] - y[j]) * 2 <= r[j])
                graph[j].push_back(i);
        }
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