#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int cc, vector<int> &visited) {
    visited[v] = cc;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, cc, visited);
}

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<int> money(vertexCount);
    for (int &m : money)
        cin >> m;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(vertexCount);
    int ccCount = 0;
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, ++ccCount, visited);

    vector<int> ccMoney(ccCount);
    for (int v = 0; v < vertexCount; v++)
        ccMoney[visited[v] - 1] += money[v];

    for (int m : ccMoney) {
        if (m) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    cout << "POSSIBLE\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}