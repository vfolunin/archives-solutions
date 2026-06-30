#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<long long, long long> dfs(vector<vector<int>> &graph, int v, vector<int> &a) {
    long long delta = 0, res = 0;
    for (int to : graph[v]) {
        auto [toDelta, toRes] = dfs(graph, to, a);
        delta += toDelta;
        res += toRes;
    }
    return { -a[v], res + abs(a[v] + delta) };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 1; v < vertexCount; v++) {
        int parent;
        cin >> parent;

        graph[parent].push_back(v);
    }

    vector<int> a(vertexCount);
    for (int &value : a)
        cin >> value;

    cout << dfs(graph, 0, a).second;
}