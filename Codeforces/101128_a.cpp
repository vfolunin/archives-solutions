#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    int res = 1;
    for (int to : graph[v])
        if (!visited[to])
            res += dfs(graph, to, visited);
    return res;
}

bool solve() {
    int minPromotions, maxPromotions, vertexCount, edgeCount;
    if (!(cin >> minPromotions >> maxPromotions >> vertexCount >> edgeCount))
        return 0;

    vector<vector<int>> graph(vertexCount), graphR(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graphR[b].push_back(a);
    }

    vector<int> res(3), visited(vertexCount);

    for (int v = 0; v < vertexCount; v++) {
        fill(visited.begin(), visited.end(), 0);
        int upCount = dfs(graph, v, visited);
        res[0] += vertexCount - upCount + 1 <= minPromotions;
        res[1] += vertexCount - upCount + 1 <= maxPromotions;
        int downCount = dfs(graphR, v, visited);
        res[2] += downCount > maxPromotions;
    }

    for (int r : res)
        cout << r << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}