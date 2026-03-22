#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color, bool &bipartite) {
    visited[v] = color;
    for (int to : graph[v]) {
        if (!visited[to])
            dfs(graph, to, visited, 3 - color, bipartite);
        else if (visited[to] == color)
            bipartite = 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, badEdgeCount;
    cin >> vertexCount >> badEdgeCount;

    if (badEdgeCount == vertexCount * (vertexCount - 1) / 2) {
        cout << "1\n1\n";
        for (int v = 1; v < vertexCount; v++)
            cout << v + 1 << " ";
        return 0;
    }

    vector<vector<int>> isBad(vertexCount, vector<int>(vertexCount));
    for (int i = 0; i < badEdgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        isBad[a][b] = isBad[b][a] = 1;
    }

    vector<vector<int>> graph(vertexCount);
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            if (a != b && !isBad[a][b])
                graph[a].push_back(b);

    vector<int> visited(graph.size());
    bool bipartite = 1;
    for (int v = 0; bipartite && v < graph.size(); v++)
        if (!visited[v])
            dfs(graph, v, visited, 1, bipartite);

    if (bipartite) {
        cout << count(visited.begin(), visited.end(), 1) << "\n";
        for (int v = 0; v < vertexCount; v++)
            if (visited[v] == 1)
                cout << v + 1 << " ";
        cout << "\n";
        for (int v = 0; v < vertexCount; v++)
            if (visited[v] == 2)
                cout << v + 1 << " ";
    } else {
        cout << -1;
    }
}