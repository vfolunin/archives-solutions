#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &tree, int v, int p, vector<int> &dist) {
    int res = 1e9;
    for (auto &[to, w] : tree[v]) {
        if (to != p) {
            dist[to] = min(dist[v], w);
            dfs(tree, to, v, dist);
        }
    }
}

bool solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount)
        return 0;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a - 1].push_back({ b - 1, w });
        graph[b - 1].push_back({ a - 1, w });
    }

    vector<vector<pair<int, int>>> mst(vertexCount);
    vector<int> used(vertexCount);
    vector<int> dist(vertexCount);
    vector<int> from(vertexCount, -1);
    set<pair<int, int>> q = { { dist[0], 0 } };

    while (!q.empty()) {
        auto [_, v] = *--q.end();
        q.erase(--q.end());

        used[v] = 1;
        if (from[v] != -1) {
            mst[from[v]].push_back({ v, dist[v] });
            mst[v].push_back({ from[v], dist[v] });
        }

        for (auto &[to, w] : graph[v]) {
            if (!used[to] && w > dist[to]) {
                q.erase({ dist[to], to });
                dist[to] = w;
                from[to] = v;
                q.insert({ dist[to], to });
            }
        }
    }

    int a, b, k;
    cin >> a >> b >> k;

    dist.assign(vertexCount, 1e9);
    dfs(mst, a - 1, -1, dist);
    int d = dist[b - 1] - 1;
    int res = (k + d - 1) / d;

    cout << "Scenario #" << test << "\n";
    cout << "Minimum Number of Trips = " << res << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}