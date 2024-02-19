#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> dfs(vector<vector<int>> &graph, int v, int p) {
    int res0 = 0, res1 = 1;

    for (int to : graph[v]) {
        if (to == p)
            continue;

        auto [count0, count1] = dfs(graph, to, v);
        res0 += count1;
        res1 += min(count0, count1);
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

    auto [res0, res1] = dfs(graph, 0, -1);

    cout << min(res0, res1);
}