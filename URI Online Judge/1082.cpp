#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(map<char, set<char>> &graph, char v, set<char> &visited, set<char> &cc) {
    visited.insert(v);
    cc.insert(v);

    for (char to : graph[v])
        if (!visited.count(to))
            dfs(graph, to, visited, cc);
}

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    map<char, set<char>> graph;
    for (int v = 0; v < vertexCount; v++)
        graph['a' + v];

    for (int i = 0; i < edgeCount; i++) {
        char a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    set<char> visited;
    set<set<char>> ccs;
    for (int v = 0; v < vertexCount; v++) {
        if (!visited.count(v + 'a')) {
            set<char> cc;
            dfs(graph, v + 'a', visited, cc);
            ccs.insert(cc);
        }
    }

    cout << "Case #" << test << ":\n";
    for (const set<char> &cc : ccs) {
        for (char v : cc)
            cout << v << ",";
        cout << "\n";
    }
    cout << ccs.size() << " connected components\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}