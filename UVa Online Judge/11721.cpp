#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, w;
};

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    vector<vector<int>> graph(vertexCount);

    for (auto &[a, b, w] : edges) {
        cin >> b >> a >> w;
        graph[a].push_back(b);
    }

    vector<long long> dist(vertexCount);
    vector<int> start;

    for (int i = 0; i < vertexCount; i++) {
        for (auto &[a, b, w] : edges) {
            if (dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                if (i == vertexCount - 1)
                    start.push_back(a);
            }
        }
    }

    vector<int> visited(vertexCount);
    for (int v : start)
        if (!visited[v])
            dfs(graph, v, visited);

    cout << "Case " << test << ":";
    bool found = 0;
    for (int v = 0; v < vertexCount; v++) {
        if (visited[v]) {
            cout << " " << v;
            found = 1;
        }
    }
    if (!found)
        cout << " impossible";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}