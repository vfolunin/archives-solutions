#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == finish)
            return dist[v];

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int a = 0; a < graph.size(); a++) {
        for (int b = 0; b < graph.size(); b++) {
            int hasEdge;
            cin >> hasEdge;
            if (hasEdge)
                graph[a].push_back(b);
        }
    }

    int start, finish;
    cin >> start >> finish;

    cout << bfs(graph, start - 1, finish - 1);
}