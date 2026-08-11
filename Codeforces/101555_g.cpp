#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(map<int, set<int>> &graph, int v, set<int> &visited) {
    visited.insert(v);
    for (int to : graph[v])
        if (!visited.count(to))
            dfs(graph, to, visited);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<int> vertices(vertexCount);
    map<int, set<int>> graph, graphR;
    for (int &v : vertices) {
        int edgeCount;
        cin >> v >> edgeCount;
        for (int j = 0; j < edgeCount; j++) {
            int to;
            cin >> to;
            graph[v].insert(to);
            graphR[to].insert(v);
        }
    }

    bool problems = 0;

    set<int> visited;
    dfs(graphR, 0, visited);
    for (int v : vertices) {
        if (!visited.count(v)) {
            cout << "TRAPPED " << v << "\n";
            problems = 1;
        }
    }

    visited.clear();
    dfs(graph, 0, visited);
    for (int v : vertices) {
        if (!visited.count(v)) {
            cout << "UNREACHABLE " << v << "\n";
            problems = 1;
        }
    }

    if (!problems)
        cout << "NO PROBLEMS\n";
}