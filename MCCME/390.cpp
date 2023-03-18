#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph;
    vector<int> visited, marked, depth, upDepth;
    set<int> cutpoints;

    Graph(int vertexCount) :
        graph(vertexCount), visited(vertexCount), marked(vertexCount), depth(vertexCount), upDepth(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool dfs1(int v, int finish) {
        visited[v] = 1;
        marked[v] = v == finish;

        for (int to : graph[v])
            if (!visited[to] && dfs1(to, finish))
                marked[v] = 1;

        return marked[v];
    }

    void dfs2(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];

        for (int to : graph[v]) {
            if (to == p) {
                continue;
            } else if (!visited[to]) {
                dfs2(to, v);
                upDepth[v] = min(upDepth[v], upDepth[to]);
                if (p != -1 && upDepth[to] >= depth[v] && marked[to])
                    cutpoints.insert(v);
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }
    }

    set<int> getCutpoints(int start, int finish) {
        dfs1(start, finish);
        visited.assign(graph.size(), 0);
        dfs2(start, -1);
        return cutpoints;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    int start, finish;
    cin >> start >> finish;

    set<int> cutpoints = graph.getCutpoints(start - 1, finish - 1);

    cout << cutpoints.size() << "\n";
    for (int c : cutpoints)
        cout << c + 1 << "\n";
}