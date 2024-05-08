#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, int p, int &res) {
    int size = 1;

    for (int to : graph[v])
        if (to != p)
            size += dfs(graph, to, v, res);

    if (size % 2 == 0) {
        res++;
        size = 0;
    }

    return size;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int res = 0;
    dfs(graph, 0, -1, res);

    cout << res - 1;
}