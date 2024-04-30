#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<pair<int, int>>> graph, graphR;
    vector<int> visited;

    Graph(int vertexCount) :
        graph(vertexCount), graphR(vertexCount) {}

    void addEdge(int a, int b, int weight) {
        graph[a].push_back({ b, weight });
        graphR[b].push_back({ a, weight });
    }

    void dfs(vector<vector<pair<int, int>>> &graph, int v, int limit) {
        visited[v] = 1;
        for (auto &[to, weight] : graph[v])
            if (!visited[to] && weight <= limit)
                dfs(graph, to, limit);
    }

    bool can(int limit) {
        visited.assign(graph.size(), 0);
        dfs(graph, 0, limit);
        if (count(visited.begin(), visited.end(), 0))
            return 0;

        visited.assign(graph.size(), 0);
        dfs(graphR, 0, limit);
        return !count(visited.begin(), visited.end(), 0);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    Graph graph(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int weight;
            cin >> weight;

            if (a != b)
                graph.addEdge(a, b, weight);
        }
    }

    int l = -1, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (graph.can(m))
            r = m;
        else
            l = m;
    }

    cout << r;
}