#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(map<int, set<int>> &graph, int v, set<int> &visited) {
    visited.insert(v);
    for (int to : graph[v])
        if (!visited.count(to))
            dfs(graph, to, visited);
}

bool solve(int test) {
    set<int> vertexSet;
    map<int, set<int>> graph;
    map<int, int> inDegree;
    int edgeCount = 0;

    while (1) {
        int a, b;
        cin >> a >> b;

        if (a < 0 && b < 0)
            return 0;

        if (!a && !b)
            break;

        vertexSet.insert(a);
        vertexSet.insert(b);
        graph[a].insert(b);
        inDegree[b]++;
        edgeCount++;
    }

    bool isTree = 1;

    if (!graph.empty()) {
        isTree = edgeCount == vertexSet.size() - 1;
        if (isTree) {
            vector<int> root;
            for (int v : vertexSet)
                if (!inDegree[v])
                    root.push_back(v);
            isTree = root.size() == 1;
            if (isTree) {
                set<int> visited;
                dfs(graph, root[0], visited);
                isTree = visited == vertexSet;
            }
        }
    }

    cout << "Case " << test << (isTree ? " is a tree.\n" : " is not a tree.\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}