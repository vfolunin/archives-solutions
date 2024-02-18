#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> dfs(vector<vector<int>> &graph, int v, int p, vector<int> &a) {
    int res0 = 0, res1 = a[v];

    for (int to : graph[v]) {
        if (to == p)
            continue;

        auto [sum0, sum1] = dfs(graph, to, v, a);
        res0 += max(sum0, sum1);
        res1 += sum0;
    }

    return { res0, res1 };
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

    vector<int> a(vertexCount);
    for (int &value : a)
        cin >> value;

    auto [res0, res1] = dfs(graph, 0, -1, a);

    cout << max(res0, res1);
}