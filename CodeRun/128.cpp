#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

void dfs(unordered_map<string, set<string>> &graph, const string &v, map<string, int> &size) {
    size[v] = 1;
    for (const string &to : graph[v]) {
        dfs(graph, to, size);
        size[v] += size[to];
    }
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

    map<string, int> size;
    for (auto &[v, _] : graph)
        if (!inDegree[v])
            dfs(graph, v, size);

    for (auto &[v, size] : size)
        cout << v << " " << size - 1 << "\n";
}