#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, int p, vector<int> &visited, vector<int> &from) {
    visited[v] = 1;
    from[v] = p;

    for (int to : graph[v]) {
        if (to == v || to == p) {
            continue;
        } else if (!visited[to]) {
            if (int c = dfs(graph, to, v, visited, from); c != -1)
                return c;
        } else if (visited[to] == 1) {
            from[to] = v;
            return to;
        }
    }

    visited[v] = 2;
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    vector<int> visited(vertexCount), from(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        if (visited[v])
            continue;
        int c = dfs(graph, v, -1, visited, from);
        if (c == -1)
            continue;

        vector<int> cycle = { c };
        for (int v = from[c]; v != c; v = from[v])
            cycle.push_back(v);
        cycle.push_back(c);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int v : cycle)
            cout << v + 1 << " ";
        return 0;
    }

    cout << "IMPOSSIBLE\n";
}