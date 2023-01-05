#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<vector<int>> &ccs) {
    visited[v] = 1;
    ccs.back().push_back(v);
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, ccs);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;
            if (hasEdge)
                graph[a].push_back(b);
        }
    }

    vector<int> visited(vertexCount);
    vector<vector<int>> ccs;
    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v]) {
            ccs.emplace_back();
            dfs(graph, v, visited, ccs);
        }
    }

    cout << ccs.size() << "\n";
    for (auto &cc : ccs) {
        cout << cc.size() << "\n";
        for (int v : cc)
            cout << v + 1 << " ";
        cout << "\n";
    }
}