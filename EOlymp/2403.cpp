#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph, graphR;
    vector<int> visited, order;

    Graph(int vertexCount) :
        graph(vertexCount), graphR(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graphR[b].push_back(a);
    }

    void dfs1(int v) {
        visited[v] = 1;
        for (int to : graph[v])
            if (!visited[to])
                dfs1(to);
        order.push_back(v);
    }

    void dfs2(int v) {
        visited[v] = 1;
        for (int to : graphR[v])
            if (!visited[to])
                dfs2(to);
    }

    int getSccCount() {
        visited.assign(graph.size(), 0);
        for (int v = 0; v < graph.size(); v++)
            if (!visited[v])
                dfs1(v);
        reverse(order.begin(), order.end());

        visited.assign(graph.size(), 0);
        int sccCount = 0;
        for (int v : order) {
            if (!visited[v]) {
                sccCount++;
                dfs2(v);
            }
        }
        return sccCount;
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

    cout << graph.getSccCount();
}