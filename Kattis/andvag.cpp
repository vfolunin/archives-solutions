#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &graph, int v, vector<int> &visited, int color) {
    visited[v] = color;
    for (auto &[to, _] : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, color);
}

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, queryCount;
    cin >> vertexCount >> edgeCount >> queryCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, mask;
        cin >> a >> b >> mask;
        a--;
        b--;

        graph[a].push_back({ b, mask });
        graph[b].push_back({ a, mask });
    }

    vector<int> visited(graph.size());
    int ccCount = 0;
    for (int v = 0; v < graph.size(); v++)
        if (!visited[v])
            dfs(graph, v, visited, ++ccCount);

    vector<int> totalMask(ccCount);
    for (int v = 0; v < graph.size(); v++)
        for (auto &[_, mask] : graph[v])
            totalMask[visited[v] - 1] |= mask;

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if (visited[a] == visited[b])
            cout << ones(totalMask[visited[a] - 1]) << "\n";
        else
            cout << "-1\n";
    }
}