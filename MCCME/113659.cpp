#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

void dfs(unordered_map<int, unordered_set<int>> &graph, int v, unordered_set<int> &visited) {
    visited.insert(v);
    for (int to : graph[v])
        dfs(graph, to, visited);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < vertexCount; i++) {
        int v, from;
        cin >> v >> from;
        if (from)
            graph[from].insert(v);
    }

    int start;
    cin >> start;
    
    unordered_set<int> visited(vertexCount);
    dfs(graph, start, visited);

    cout << visited.size();
}