#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(map<string, set<string>> &graph, const string &v, map<string, int> &visited) {
    visited[v] = 1;
    for (const string &to : graph[v])
        if (visited[to] == 1 || visited[to] == 0 && dfs(graph, to, visited))
            return 1;
    visited[v] = 2;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int edgeCount;
    cin >> edgeCount;

    map<string, set<string>> graph;
    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        cin >> a >> b;
        graph[a].insert(b);
    }

    string start;
    while (cin >> start) {
        map<string, int> visited;
        cout << start << (dfs(graph, start, visited) ? " safe\n" : " trapped\n");
    }
}