#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, int depth, int finish, int limit, vector<int> &visited) {
    if (depth > limit)
        return 0;

    if (v == finish)
        return 1;

    visited[v] = 1;
    int res = 0;

    for (int to : graph[v])
        if (!visited[to])
            res += dfs(graph, to, depth + 1, finish, limit, visited);

    visited[v] = 0;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, start, finish, limit;
    cin >> vertexCount >> edgeCount >> start >> finish >> limit;
    start--;
    finish--;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
    }

    vector<int> visited(vertexCount);
    cout << dfs(graph, start, 0, finish, limit, visited);
}