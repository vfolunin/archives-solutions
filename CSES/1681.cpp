#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

long long rec(vector<vector<int>> &graph, int v) {
    static vector<int> memo(1e5 + 1, -1);
    if (memo[v] != -1)
        return memo[v];

    if (v == graph.size() - 1)
        return memo[v] = 1;

    memo[v] = 0;
    for (int to : graph[v])
        memo[v] = (memo[v] + rec(graph, to)) % MOD;
    return memo[v];
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
        graph[a - 1].push_back(b - 1);
    }

    cout << rec(graph, 0);
}