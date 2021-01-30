#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(map<string, vector<string>> &graph, string v, set<string> &visited) {
    visited.insert(v);
    int res = 1;
    for (string &to : graph[v])
        if (!visited.count(to))
            res += dfs(graph, to, visited);
    return res;
}

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    for (int i = 0; i < vertexCount; i++) {
        string line;
        cin >> line;
    }

    map<string, vector<string>> graph;
    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    set<string> visited;
    int res = 1;
    for (auto &[v, _] : graph)
        res = max(res, dfs(graph, v, visited));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}