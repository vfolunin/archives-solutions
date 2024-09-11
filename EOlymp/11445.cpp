#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    struct Edge {
        int a, b, w;
    };

    vector<Edge> edges;
    vector<vector<int>> g, gr;
    vector<int> reachable, reachableR;

    Graph(int vertexCount) {
        g.resize(vertexCount);
        gr.resize(vertexCount);
        reachable.resize(vertexCount);
        reachableR.resize(vertexCount);
    }

    void addEdge(int a, int b, int w) {
        edges.push_back({ a, b, w });
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    void dfs(vector<vector<int>> &g, int v, vector<int> &reachable) {
        reachable[v] = 1;
        for (int to : g[v])
            if (!reachable[to])
                dfs(g, to, reachable);
    }

    long long fordBellman() {
        dfs(g, 0, reachable);
        dfs(gr, g.size() - 1, reachableR);

        vector<long long> dist(g.size(), -(1LL << 60));
        dist[0] = 0;

        for (int i = 0; i < g.size(); i++) {
            for (auto &[a, b, w] : edges) {
                if (dist[b] < dist[a] + w) {
                    if (i + 1 == g.size() && reachable[a] && reachableR[b])
                        return -1;
                    dist[b] = dist[a] + w;
                }
            }
        }

        return dist[g.size() - 1];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph.addEdge(a - 1, b - 1, w);
    }

    cout << graph.fordBellman();
}