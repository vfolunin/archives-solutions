#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(map<string, set<string>> &graph, const string &v, set<string> &visited) {
    visited.insert(v);
    for (const string &to : graph[v])
        if (!visited.count(to))
            dfs(graph, to, visited);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    map<string, set<string>> graph;

    for (int i = 0; i < edgeCount; i++) {
        string a, op, b;
        cin >> a >> op >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    set<string> visited;
    int ccCount = 0;

    for (auto &[v, _] : graph) {
        if (!visited.count(v)) {
            ccCount++;
            dfs(graph, v, visited);
        }
    }

    cout << ccCount << "\n";
}