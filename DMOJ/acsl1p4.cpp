#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(vector<vector<int>> &graph, int start, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (to == start || !visited[to] && dfs(graph, start, to, visited))
            return 1;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, scoreA, scoreB;
        cin >> a >> b >> scoreA >> scoreB;
        a--;
        b--;

        if (scoreA > scoreB)
            graph[a].push_back(b);
        else
            graph[b].push_back(a);
    }

    int res = 0;
    for (int v = 0; v < vertexCount; v++) {
        vector<int> visited(vertexCount);
        res += dfs(graph, v, v, visited);
    }
    
    cout << res;
}