#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, used = 0;

    int other(int v) {
        return v == b ? a : b;
    }
};

int dfs(vector<Edge> &edges, vector<vector<int>> &graph, int v) {
    int res = 0;
    for (int ei : graph[v]) {
        if (!edges[ei].used) {
            edges[ei].used = 1;
            res = max(res, 1 + dfs(edges, graph, edges[ei].other(v)));
            edges[ei].used = 0;
        }
    }
    return res;
}

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    vector<Edge> edges(edgeCount);
    vector<vector<int>> graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        cin >> edges[i].a >> edges[i].b;
        graph[edges[i].a].push_back(i);
        graph[edges[i].b].push_back(i);
    }

    int res = 0;
    for (int start = 0; start < vertexCount; start++)
        res = max(res, dfs(edges, graph, start));
    
    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}