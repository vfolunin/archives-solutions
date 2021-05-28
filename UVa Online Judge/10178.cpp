#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getId(map<char, int> &vertexId, char c) {
    if (!vertexId.count(c))
        vertexId[c] = vertexId.size();
    return vertexId[c];
}

pair<int, int> dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1; 
    int vertices = 1, edges = 0;

    for (int to : graph[v]) {
        edges++;
        if (!visited[to]) {
            auto [verticesTo, edgesTo] = dfs(graph, to, visited);
            vertices += verticesTo;
            edges += edgesTo;
        }
    }

    return { vertices, edges };
}

bool solve() {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    map<char, int> vertexId;
    vector<vector<int>> graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        char a, b;
        cin >> a >> b;

        graph[getId(vertexId, a)].push_back(getId(vertexId, b));
        graph[getId(vertexId, b)].push_back(getId(vertexId, a));
    }

    int res = 1;
    vector<int> visited(vertexCount);

    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v]) {
            auto [vertices, edges] = dfs(graph, v, visited);
            res += 1 + edges / 2 - vertices;
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}