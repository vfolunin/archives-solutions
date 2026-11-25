#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long dfs(vector<vector<int>> &graph, int v, int parent, vector<int> &a,
              long long totalSize, int &bestV, long long &bestQSize) {
    long long size = a[v], qSize = a[v], upSize = totalSize - a[v];

    for (int to : graph[v]) {
        if (to == parent)
            continue;

        long long toSize = dfs(graph, to, v, a, totalSize, bestV, bestQSize);
        size += toSize;
        qSize = max(qSize, toSize);
        upSize -= toSize;
    }

    qSize = max(qSize, upSize);
    if (bestQSize > qSize) {
        bestV = v;
        bestQSize = qSize;
    }

    return size;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<int> a(vertexCount);
    long long totalSize = 0;
    for (int &value : a) {
        cin >> value;
        totalSize += value;
    }

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < graph.size() - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int bestV = -1;
    long long bestQSize = 1e18;
    dfs(graph, 0, -1, a, totalSize, bestV, bestQSize);

    cout << bestV + 1;
}