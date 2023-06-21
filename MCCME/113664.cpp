#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(map<int, set<int>> &graph, int v, int offset) {
    for (int to : graph[v]) {
        cout << string(offset, '*') << to << "\n";
        dfs(graph, to, offset + 2);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    map<int, set<int>> graph;
    for (int i = 0; i < vertexCount; i++) {
        int v, from;
        cin >> v >> from;
        graph[from].insert(v);
    }

    dfs(graph, 0, 0);
}