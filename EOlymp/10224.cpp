#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph;
    vector<int> visited, time, upTime;
    int timer = 1;

    void dfs(int v, int p) {
        visited[v] = 1;
        time[v] = timer++;
        upTime[v] = time[v];

        sort(graph[v].begin(), graph[v].end());

        for (int to : graph[v]) {
            if (to == p) {
                continue;
            } else if (!visited[to]) {
                dfs(to, v);
                upTime[v] = min(upTime[v], upTime[to]);
            } else {
                upTime[v] = min(upTime[v], time[to]);
            }
        }
    }

    Graph(int vertexCount) :
        graph(vertexCount), visited(vertexCount), time(vertexCount), upTime(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
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

    int root;
    cin >> root;

    graph.dfs(root - 1, -1);

    for (int v = 0; v < vertexCount; v++)
        cout << graph.time[v] << " " << graph.upTime[v] << "\n";
}