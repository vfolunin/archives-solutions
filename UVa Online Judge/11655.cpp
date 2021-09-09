#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e5;

void dfs(vector<vector<int>> &graph, int v, int target, vector<int> &visited, vector<int> &pathCount) {
    visited[v] = 1;
    pathCount[v] = v == target;

    for (int to : graph[v]) {
        if (!visited[to])
            dfs(graph, to, target, visited, pathCount);
        pathCount[v] = (pathCount[v] + pathCount[to]) % MOD;
    }
}

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount), graphR(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graphR[b].push_back(a);
    }

    vector<int> visited(vertexCount), pathCount(vertexCount);
    dfs(graph, 0, vertexCount - 1, visited, pathCount);

    vector<int> visitedR(vertexCount), pathCountR(vertexCount);
    dfs(graphR, vertexCount - 1, 0, visitedR, pathCountR);

    long long teamCount = 0;
    for (int v = 0; v < vertexCount; v++)
        for (int to : graph[v])
            teamCount = (teamCount + 1LL * pathCountR[v] * pathCount[to]) % MOD;

    cout << "Case " << test << ": " << teamCount << " " << pathCount[0] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}