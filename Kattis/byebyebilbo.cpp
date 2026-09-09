#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int parent, vector<int> &depth) {
    depth[v] = parent == -1 ? 0 : depth[parent] + 1;
    for (int to : graph[v])
        dfs(graph, to, v, depth);
}

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, dist;
    cin >> vertexCount >> dist;

    vector<int> parent(vertexCount);
    for (int v = 1; v < parent.size(); v++) {
        cin >> parent[v];
        parent[v]--;
    }

    vector<vector<int>> graph(vertexCount);
    for (int v = 1; v < vertexCount; v++)
        graph[parent[v]].push_back(v);

    vector<int> depth(vertexCount);
    dfs(graph, 0, -1, depth);

    vector<int> order(vertexCount);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return depth[a] > depth[b];
    });

    vector<int> visited(vertexCount), res;
    for (int v : order) {
        if (!visited[v]) {
            int resV = v;
            for (int i = 0; i < dist - 1 && resV; i++)
                resV = parent[resV];

            res.push_back(resV);
            dfs(graph, resV, visited);
        }
    }

    cout << res.size() << "\n";
    for (int v : res)
        cout << v + 1 << " ";
}