#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, int threshold) {
    if (graph[v].empty())
        return 1;

    vector<int> children;
    for (int to : graph[v])
        children.push_back(dfs(graph, to, threshold));
    sort(children.begin(), children.end());

    int k = (threshold * children.size() + 99) / 100;
    int res = 0;
    for (int i = 0; i < k; i++)
        res += children[i];
    return res;
}

bool solve() {
    int vertexCount, threshold;
    cin >> vertexCount >> threshold;

    if (!vertexCount)
        return 0;

    vector<vector<int>> graph(vertexCount + 1);
    for (int v = 1; v <= vertexCount; v++) {
        int p;
        cin >> p;
        graph[p].push_back(v);
    }

    cout << dfs(graph, 0, threshold) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}