#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> dfs(vector<vector<int>> &graph, vector<int> &weight, int v, int p) {
    int actions = 0, pool = 0;
    for (int to : graph[v]) {
        if (to != p) {
            auto [a, p] = dfs(graph, weight, to, v);
            actions += a;
            pool += p;
        }
    }
    pool += weight[v] - 1;
    actions += abs(pool);
    return { actions, pool };
}

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> graph(vertexCount);
    vector<int> weight(vertexCount);

    for (int i = 0; i < vertexCount; i++) {
        int v, edgeCount;
        cin >> v >> weight[v - 1] >> edgeCount;
        for (int j = 0; j < edgeCount; j++) {
            int to;
            cin >> to;
            graph[v - 1].push_back(to - 1);
            graph[to - 1].push_back(v - 1);
        }
    }

    auto [actions, _] = dfs(graph, weight, 0, -1);

    cout << actions << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}