#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph, up;

    Graph(int vertexCount) : graph(vertexCount), up(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void dfs(int v, int p) {
        up[v].push_back(p);
        for (int i = 1; i < 20; i++)
            up[v].push_back(up[v][i - 1] == -1 ? -1 : up[up[v][i - 1]][i - 1]);

        for (int to : graph[v])
            if (to != p)
                dfs(to, v);
    }

    int nthAncestor(int v, int n) {
        for (int i = 19; i >= 0; i--) {
            if (n > (1 << i)) {
                n -= (1 << i);
                v = up[v][i];
                if (v == -1)
                    return -1;
            }
        }
        return up[v][0];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, queryCount;
    cin >> vertexCount >> queryCount;

    Graph graph(vertexCount);

    for (int v = 1; v < vertexCount; v++) {
        int p;
        cin >> p;
        graph.addEdge(p - 1, v);
    }

    graph.dfs(0, -1);

    for (int i = 0; i < queryCount; i++) {
        int v, n;
        cin >> v >> n;

        int res = graph.nthAncestor(v - 1, n);
        cout << (res != -1 ? res + 1 : -1) << "\n";
    }
}