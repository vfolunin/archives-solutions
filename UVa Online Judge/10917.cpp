#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9);
    set<pair<int, int>> q;

    dist[start] = 0;
    q.insert({ dist[start], start });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist;
}

void dfs(vector<vector<pair<int, int>>> &graph, int v, int finish, vector<int> &dist, vector<int> &res) {
    res[v] = v == finish;
    for (auto &[to, _] : graph[v]) {
        if (dist[v] > dist[to]) {
            if (res[to] == -1)
                dfs(graph, to, finish, dist, res);
            res[v] += res[to];
        }
    }
}

bool solve() {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a - 1].push_back({ b - 1, w });
        graph[b - 1].push_back({ a - 1, w });
    }

    vector<int> dist = dijkstra(graph, 1);
    vector<int> res(vertexCount, -1);
    dfs(graph, 0, 1, dist, res);

    cout << res[0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}