#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<set<int>> &graph, int v, vector<int> &visited, int offset) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (!visited[to]) {
            cout << string(offset, ' ') << v << "-" << to << " pathR(G," << to << ")\n";
            dfs(graph, to, visited, offset + 2);
        } else {
            cout << string(offset, ' ') << v << "-" << to << "\n";
        }
    }
}

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<set<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
    }

    cout << "Caso " << test << ":";

    vector<int> visited(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v] && graph[v].size()) {
            cout << "\n";
            dfs(graph, v, visited, 2);
        }
    }

    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}