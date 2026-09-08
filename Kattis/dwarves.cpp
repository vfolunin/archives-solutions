#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

void dfs(unordered_map<string, unordered_set<string>> &graph, const string &v, unordered_map<string, int> &visited, bool &hasCycle) {
    visited[v] = 1;
    for (const string &to : graph[v])
        if (!visited.count(to))
            dfs(graph, to, visited, hasCycle);
        else if (visited[to] == 1)
            hasCycle = 1;
    visited[v] = 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int edgeCount;
    cin >> edgeCount;

    unordered_map<string, unordered_set<string>> graph;
    for (int i = 0; i < edgeCount; i++) {
        string a, op, b;
        cin >> a >> op >> b;

        graph[a];
        graph[b];

        if (op == ">")
            graph[a].insert(b);
        else
            graph[b].insert(a);
    }

    unordered_map<string, int> visited;
    bool hasCycle = 0;
    for (auto &[v, _] : graph)
        if (!visited.count(v))
            dfs(graph, v, visited, hasCycle);
    
    cout << (hasCycle ? "impossible" : "possible");
}