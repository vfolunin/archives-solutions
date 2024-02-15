#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void printCycle(vector<int> &from, int lastVertex) {
    vector<int> cycle = { lastVertex };
    for (int v = from[lastVertex]; v != lastVertex; v = from[v])
        cycle.push_back(v);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int v : cycle)
        cout << v + 1 << " ";
}

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &from) {
    visited[v] = 1;
    for (int to : graph[v]) {
        from[to] = v;
        if (visited[to] == 0) {
            dfs(graph, to, visited, from);
        } else if (visited[to] == 1) {
            printCycle(from, to);
            exit(0);
        }
    }
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

    vector<int> visited(vertexCount), from(vertexCount, -1);
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, visited, from);

    cout << "NO";
}