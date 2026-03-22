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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
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