#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

void dfs(unordered_map<string, set<string>> &graph, const string &v, map<string, int> &depth, int d) {
    depth[v] = d;
    for (const string &to : graph[v])
        dfs(graph, to, depth, d + 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int vertexCount;
    cin >> vertexCount;

    unordered_map<string, set<string>> graph;
    unordered_map<string, int> inDegree;
    for (int i = 0; i < vertexCount - 1; i++) {
        string a, b;
        cin >> a >> b;
        graph[b].insert(a);
        inDegree[a]++;
    }

    map<string, int> depth;
    for (auto &[v, _] : graph)
        if (!inDegree[v])
            dfs(graph, v, depth, 0);

    for (auto &[v, depth] : depth)
        cout << v << " " << depth << "\n";
}