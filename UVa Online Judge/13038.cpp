#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &maxPath) {
    maxPath[v] = 1;
    for (int to : graph[v]) {
        if (!maxPath[to])
            dfs(graph, to, maxPath);
        maxPath[v] = max(maxPath[v], 1 + maxPath[to]);
    }
}

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    vector<int> maxPath(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        if (!maxPath[v])
            dfs(graph, v, maxPath);

    int res = *max_element(maxPath.begin(), maxPath.end());

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}