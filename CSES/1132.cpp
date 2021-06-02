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
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    vector<int> distA(vertexCount), distB(vertexCount);
    dfs(graph, 0, -1, distA);
    int a = max_element(distA.begin(), distA.end()) - distA.begin();
    dfs(graph, a, -1, distA);
    int b = max_element(distA.begin(), distA.end()) - distA.begin();
    dfs(graph, b, -1, distB);

    for (int v = 0; v < vertexCount; v++)
        cout << max(distA[v], distB[v]) << " ";
}