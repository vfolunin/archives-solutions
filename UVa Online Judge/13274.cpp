#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, int p, int childCount) {
    vector<int> remain;
    for (int to : graph[v])
        if (to != p)
            remain.push_back(dfs(graph, to, v, childCount));

    int res = 1;
    if (remain.size() >= childCount) {
        sort(remain.rbegin(), remain.rend());
        for (int i = 0; i < childCount; i++)
            res += remain[i];
    }
    return res;
}

void solve(int test) {
    int vertexCount, childCount;
    cin >> vertexCount >> childCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    cout << "Case " << test << ": " << dfs(graph, 0, -1, childCount) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}