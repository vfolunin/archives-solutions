#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &size, vector<long long> &res) {
    if (size[v])
        return;
    size[v] = 1;

    for (int to : graph[v]) {
        dfs(graph, to, size, res);
        size[v] += size[to];
        res[v] += size[to];

        for (int to2 : graph[v]) {
            if (to2 == to)
                break;
            res[v] += size[to] * size[to2];
        }
    }
}

void solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);

    for (int v = 0; v < vertexCount; v++) {
        int p;
        cin >> p;
        if (p)
            graph[p - 1].push_back(v);
    }

    vector<int> size(vertexCount);
    vector<long long> res(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        dfs(graph, v, size, res);

    cout << "Forest#" << test << ": ";
    for (int v = 0; v < vertexCount; v++)
        cout << res[v] << (v + 1 < vertexCount ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}