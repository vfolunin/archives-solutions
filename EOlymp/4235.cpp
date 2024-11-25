#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> bfs(vector<vector<int>> &graph, const int start) {
    vector<int> dist(graph.size(), 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int to = 1; to < vertexCount; to++) {
        int v;
        cin >> v;
        v--;

        graph[v].push_back(to);
        graph[to].push_back(v);
    }

    vector<int> dist = bfs(graph, 0);
    int a = max_element(dist.begin(), dist.end()) - dist.begin();

    vector<int> distA = bfs(graph, a);
    int b = max_element(distA.begin(), distA.end()) - distA.begin();
    int diameter = distA[b];

    vector<int> distB = bfs(graph, b), roots;
    for (int v = 0; v < vertexCount; v++)
        if (distA[v] + distB[v] == diameter && abs(distA[v] - distB[v]) <= 1)
            cout << v + 1 << " ";
}