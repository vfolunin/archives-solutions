#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int p, vector<vector<int>> &coverSize) {
    coverSize[v][1] = 1;

    for (int to : graph[v]) {
        if (to == p)
            continue;

        dfs(graph, to, v, coverSize);

        coverSize[v][0] += coverSize[to][1];
        coverSize[v][1] += min(coverSize[to][0], coverSize[to][1]);
    }
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

    vector<vector<int>> coverSize(vertexCount, vector<int>(2));
    dfs(graph, 0, -1, coverSize);

    cout << min(coverSize[0][0], coverSize[0][1]);
}