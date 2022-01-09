#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    int vertices = 1, edges = graph[v].size();
    for (int to : graph[v]) {
        if (!visited[to]) {
            auto [toVertices, toEdges] = dfs(graph, to, visited);
            vertices += toVertices;
            edges += toEdges;
        }
    }
    return { vertices, edges };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);

    for (int a = 0; a < vertexCount; a++) {
        string line;
        cin >> line;
        for (int b = 0; b < vertexCount; b++)
            if (line[b] == 'S')
                graph[a].push_back(b);
    }

    vector<int> visited(vertexCount);
    vector<int> ccSize;

    for (int v = 0; v < vertexCount; v++)
        if (!visited[v]) {
            auto [vertices, edges] = dfs(graph, v, visited);
            if (vertices * vertices != edges) {
                cout << "-1\n";
                return 0;
            }
            ccSize.push_back(vertices);
        }
    sort(ccSize.rbegin(), ccSize.rend());

    cout << ccSize.size() << "\n";
    for (int i = 0; i < ccSize.size(); i++)
        cout << ccSize[i] << (i + 1 < ccSize.size() ? " " : "\n");
}