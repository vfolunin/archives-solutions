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

void dfs(vector<vector<int>> &graph, int start, vector<int> &visited) {
    vector<int> from(graph.size(), -1), index(graph.size()), stack;

    visited[start] = 1;
    stack.push_back(start);

    while (!stack.empty()) {
        int v = stack.back();

        if (index[v] == graph[v].size()) {
            visited[v] = 2;
            stack.pop_back();
        } else {
            int to = graph[v][index[v]++];

            if (visited[to] == 0) {
                visited[to] = 1;
                from[to] = v;
                stack.push_back(to);
            } else if (visited[to] == 1) {
                from[to] = v;
                printCycle(from, to);
                exit(0);
            }
        }
    }
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

    vector<int> visited(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, visited);

    cout << "NO";
}