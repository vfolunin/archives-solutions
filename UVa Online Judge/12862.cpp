#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &graph, int v, int p, vector<int> &hasFriend, vector<vector<int>> &cost) {
    int delta10 = 0;
    for (auto &[to, w] : graph[v]) {
        if (to != p) {
            dfs(graph, to, v, hasFriend, cost);
            hasFriend[v] |= hasFriend[to];
            if (hasFriend[to]) {
                cost[v][1] += cost[to][1] + w;
                delta10 = max(delta10, cost[to][1] + w - cost[to][0]);
            }
        }
    }
    cost[v][0] = cost[v][1] - delta10;
}

bool solve() {
    int vertexCount, friendCount;
    if (!(cin >> vertexCount >> friendCount))
        return 0;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    vector<int> hasFriend(vertexCount);
    for (int i = 0; i < friendCount; i++) {
        int v;
        cin >> v;
        hasFriend[v - 1] = 1;
    }

    vector<vector<int>> cost(vertexCount, vector<int>(2));
    dfs(graph, 0, -1, hasFriend, cost);

    cout << cost[0][0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}