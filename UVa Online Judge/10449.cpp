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

bool solve(int test) {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    vector<int> bonus(vertexCount);
    for (int &b : bonus)
        cin >> b;

    int edgeCount;
    cin >> edgeCount;

    vector<Edge> edges(edgeCount);
    vector<vector<int>> graph(vertexCount);

    for (auto &[a, b, w] : edges) {
        cin >> a >> b;
        a--;
        b--;
        int delta = bonus[b] - bonus[a];
        w = delta * delta * delta;
        graph[a].push_back(b);
    }

    const int INF = 1e9;
    vector<int> dist(vertexCount, INF), negative(vertexCount);
    if (vertexCount)
        dist[0] = 0;

    for (int i = 0; i < vertexCount; i++) {
        for (auto &[a, b, w] : edges) {
            if (dist[a] != INF && dist[b] > dist[a] + w) {
                dist[b] = max(-INF, dist[a] + w);
                if (i == vertexCount - 1)
                    dfs(graph, a, negative);
            }
        }
    }

    int queryCount;
    cin >> queryCount;

    cout << "Set #" << test << "\n";
    for (int i = 0; i < queryCount; i++) {
        int v;
        cin >> v;
        v--;

        int res = -INF;
        if (!negative[v] && dist[v] != INF)
            res = dist[v];

        if (res >= 3)
            cout << res << "\n";
        else
            cout << "?\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}