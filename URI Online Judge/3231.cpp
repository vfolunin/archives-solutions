#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &graph, vector<int> &startVertices) {
    vector<int> dist(graph.size(), 1e9);
    queue<int> q;

    for (int start : startVertices) {
        dist[start] = 0;
        q.push(start);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] == 1e9) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return max_element(dist.begin(), dist.end()) - dist.begin();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, startVertexCount, edgeCount;
    cin >> vertexCount >> startVertexCount >> edgeCount;

    vector<int> startVertices(startVertexCount);
    for (int &startVertex : startVertices)
        cin >> startVertex;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << bfs(graph, startVertices) << "\n";
}