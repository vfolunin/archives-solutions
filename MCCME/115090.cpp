#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph;
    vector<int> l, r;
    int timer;

    Graph(int vertexCount) : graph(vertexCount), l(vertexCount), r(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void dfs(int v) {
        l[v] = ++timer;
        for (int to : graph[v])
            if (!l[to])
                dfs(to);
        r[v] = ++timer;
    }

    void prepare(int root) {
        timer = 0;
        dfs(root);
    }

    bool isAncestor(int a, int b) {
        return l[a] <= l[b] && r[b] <= r[a];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int vertexCount;
    cin >> vertexCount;

    Graph graph(vertexCount);
    int root = -1;

    for (int v = 0; v < vertexCount; v++) {
        int from;
        cin >> from;

        if (from)
            graph.addEdge(from - 1, v);
        else
            root = v;
    }

    graph.prepare(root);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;

        cout << graph.isAncestor(a - 1, b - 1) << "\n";
    }
}