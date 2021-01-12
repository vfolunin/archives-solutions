#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &tree, int v, int p, vector<int> &dist) {
    int res = 0;
    for (auto &[to, w] : tree[v]) {
        if (to != p) {
            dist[to] = max(dist[v], w);
            dfs(tree, to, v, dist);
        }
    }
}

bool solve(int test) {
    int vertexCount, edgeCount, queryCount;
    cin >> vertexCount >> edgeCount >> queryCount;

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
    vector<int> dist(vertexCount, 1e9);
    vector<int> from(vertexCount, -1);
    set<pair<int, int>> q;

    for (int v = 0; v < vertexCount; v++) {
        if (dist[v] != 1e9)
            continue;

        dist[v] = 0;
        q.insert({ dist[v], v });

        while (!q.empty()) {
            auto [_, v] = *q.begin();
            q.erase(q.begin());

            used[v] = 1;
            if (from[v] != -1) {
                mst[from[v]].push_back({ v, dist[v] });
                mst[v].push_back({ from[v], dist[v] });
            }

            for (auto [to, w] : graph[v]) {
                if (!used[to] && w < dist[to]) {
                    q.erase({ dist[to], to });
                    dist[to] = w;
                    from[to] = v;
                    q.insert({ dist[to], to });
                }
            }
        }
    }

    if (test > 1)
        cout << "\n";
    cout << "Case #" << test << "\n";
    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;

        vector<int> dist(vertexCount, 1e9);
        dist[a - 1] = 0;
        dfs(mst, a - 1, -1, dist);

        if (dist[b - 1] != 1e9)
            cout << dist[b - 1] << "\n";
        else
            cout << "no path\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}