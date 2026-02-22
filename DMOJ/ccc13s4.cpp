#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

bool hasPath(vector<vector<int>> &graph, int a, int b) {
    vector<int> visited(graph.size());
    dfs(graph, a, visited);
    return visited[b];
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
        a--;
        b--;

        graph[a].push_back(b);
    }

    int a, b;
    cin >> a >> b;
    a--;
    b--;

    if (hasPath(graph, a, b))
        cout << "yes";
    else if (hasPath(graph, b, a))
        cout << "no";
    else
        cout << "unknown";
}