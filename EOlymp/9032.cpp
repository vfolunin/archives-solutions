#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int p, vector<int> &visited, int &cycle) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (to == p)
            continue;
        else if (!visited[to])
            dfs(graph, to, v, visited, cycle);
        else if (visited[to] == 1)
            cycle = 1;
    }
    visited[v] = 2;
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
    int res = 0;
    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v]) {
            int cycle = 0;
            dfs(graph, v, -1, visited, cycle);
            res += !cycle;
        }
    }

    cout << res;
}