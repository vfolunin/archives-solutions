#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    int vertexCount;
    vector<vector<int>> g;
    vector<int> size;
    vector<long long> dist;

    void dfs1(int v, int p) {
        size[v] = 1;
        for (int to : g[v]) {
            if (to != p) {
                dfs1(to, v);
                size[v] += size[to];
                dist[v] += dist[to] + size[to];
            }
        }
    }

    void dfs2(int v, int p) {
        if (p != -1)
            dist[v] += dist[p] - (dist[v] + size[v]) + (vertexCount - size[v]);
        for (int to : g[v])
            if (to != p)
                dfs2(to, v);
    }

    Graph(int vertexCount) : vertexCount(vertexCount), g(vertexCount), size(vertexCount), dist(vertexCount) {}

    void addEdge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<long long> getDist() {
        dfs1(0, -1);
        dfs2(0, -1);
        return dist;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    Graph graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    for (auto d : graph.getDist())
        cout << d << " ";
}