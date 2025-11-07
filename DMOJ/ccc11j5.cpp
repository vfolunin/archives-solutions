#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, vector<int> &vMask) {
    vMask[v] |= 1 << v;
    for (int to : graph[v])
        vMask[v] |= dfs(graph, to, vMask);
    return vMask[v];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount - 1; v++) {
        int parent;
        cin >> parent;

        graph[parent - 1].push_back(v);
    }

    vector<int> vMask(vertexCount);
    dfs(graph, vertexCount - 1, vMask);

    int res = 0;
    for (int mask = 0; mask < (1 << vertexCount); mask++) {
        if (mask & (1 << (vertexCount - 1)))
            continue;

        int ok = 1;
        for (int v = 0; v < vertexCount; v++)
            ok &= !(mask & (1 << v)) || (mask & vMask[v]) == vMask[v];
        res += ok;
    }

    cout << res;
}