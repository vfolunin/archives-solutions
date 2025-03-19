#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

bool dfs(unordered_map<string, unordered_set<string>> &graph,
         const string &start, const string &v,
         unordered_set<string> &visited) {
    visited.insert(v);
    for (const string &to : graph[v])
        if (to == start || !visited.count(to) && dfs(graph, start, to, visited))
            return 1;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<string> vertices(vertexCount);
    unordered_map<string, unordered_set<string>> graph;

    for (string &v : vertices) {
        int degree;
        cin >> v >> degree;

        for (int i = 0; i < degree; i++) {
            string to;
            cin >> to;

            graph[v].insert(to);
        }

        string sep;
        cin >> sep;
    }

    for (string &v : vertices) {
        unordered_set<string> visited;
        cout << v << ": " << (dfs(graph, v, v, visited) ? "YES\n" : "NO\n");
    }
}