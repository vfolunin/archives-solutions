#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, bool &hasCycle) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (!visited[to])
            dfs(graph, to, visited, hasCycle);
        else if (visited[to] == 1)
            hasCycle = 1;
    }
    visited[v] = 2;
}

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    vector<vector<int>> graph(26);
    for (int i = 0; i + 1 < a.size(); i++) {
        int pos = 0;
        while (pos < a[i].size() && pos < a[i + 1].size() && a[i][pos] == a[i + 1][pos])
            pos++;

        if (pos < a[i].size() && pos == a[i + 1].size()) {
            cout << "no\n";
            return 1;
        }

        if (pos < a[i].size() && pos < a[i + 1].size())
            graph[a[i][pos] - 'a'].push_back(a[i + 1][pos] - 'a');
    }

    vector<int> visited(graph.size());
    bool hasCycle = 0;
    for (int v = 0; v < graph.size() && !hasCycle; v++)
        if (!visited[v])
            dfs(graph, v, visited, hasCycle);

    cout << (hasCycle ? "no\n" : "yes\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}