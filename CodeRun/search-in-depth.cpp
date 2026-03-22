#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &cc) {
    visited[v] = 1;
    cc.push_back(v);
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, cc);
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

    vector<int> visited(vertexCount), cc;
    dfs(graph, 0, visited, cc);
    sort(cc.begin(), cc.end());

    cout << cc.size() << "\n";
    for (int v : cc)
        cout << v + 1 << " ";
}