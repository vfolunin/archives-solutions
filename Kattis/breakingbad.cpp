#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(map<string, set<string>> &graph, const string &v, map<string, int> &visited, int color) {
    visited[v] = color;
    for (const string &to : graph[v])
        if (visited[to] == color || visited[to] == 0 && dfs(graph, to, visited, 3 - color))
            return 1;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    map<string, set<string>> graph;
    for (int i = 0; i < vertexCount; i++) {
        string vertex;
        cin >> vertex;
        graph[vertex];
    }

    int edgeCount;
    cin >> edgeCount;
    
    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    map<string, int> visited;
    for (auto &[v, _] : graph) {
        if (!visited[v] && dfs(graph, v, visited, 1)) {
            cout << "impossible";
            return 0;
        }
    }

    for (int part = 1; part <= 2; part++) {
        for (auto &[v, color] : visited)
            if (color == part)
                cout << v << " ";
        cout << "\n";
    }
}