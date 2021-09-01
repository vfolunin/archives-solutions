#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(map<char, set<char>> &graph, char v, map<char, int> &size) {
    size[v] = graph[v].empty();
    for (char to : graph[v]) {
        if (!size.count(to))
            dfs(graph, to, size);
        size[v] += size[to];
    }
}

int getIndex(string &path, int i, map<char, set<char>> &graph, map<char, int> &size) {
    int res = 0;
    for (char to : graph[path[i]]) {
        if (to < path[i + 1]) {
            res += size[to];
        } else {
            res += getIndex(path, i + 1, graph, size);
            break;
        }
    }
    return res;
}

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    map<char, set<char>> graph;
    for (int i = 0; i < edgeCount; i++) {
        char a, b;
        cin >> a >> b;
        graph[a].insert(b);
    }

    map<char, int> size;
    for (auto &[v, _] : graph)
        if (!size.count(v))
            dfs(graph, v, size);

    int pathCount;
    cin >> pathCount;

    for (int i = 0; i < pathCount; i++) {
        string path;
        cin >> path;

        cout << path << ": " << getIndex(path, 0, graph, size) + 1 << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}