#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int p, vector<int> &dist) {
    dist[v] = (p == -1 ? 0 : dist[p] + 1);
    for (int to : graph[v])
        if (to != p)
            dfs(graph, to, v, dist);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> dist(vertexCount);
    dfs(graph, 0, -1, dist);
    dfs(graph, max_element(dist.begin(), dist.end()) - dist.begin(), -1, dist);

    cout << *max_element(dist.begin(), dist.end());
}