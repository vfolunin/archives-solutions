#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long dfs(vector<vector<int>> &graph, int v) {
    long long res = 1;
    static const long long MOD = 1e9 + 7;

    for (int to : graph[v])
        res = res * (1 + dfs(graph, to)) % MOD;

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 1; v < vertexCount; v++) {
        int p;
        cin >> p;
        graph[p - 1].push_back(v);
    }

    cout << dfs(graph, 0);
}