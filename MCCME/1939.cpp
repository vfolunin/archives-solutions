#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> bfs(vector<vector<int>> &graph, vector<int> &start) {
    vector<int> dist(graph.size(), 1e9);
    queue<int> q;

    for (int v : start) {
        dist[v] = 0;
        q.push(v);
    }

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

    int vertexCount, startCount;
    cin >> vertexCount >> startCount;

    vector<int> start(startCount);
    for (int &v : start) {
        cin >> v;
        v--;
    }

    int edgeCount;
    cin >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int dist : bfs(graph, start))
        cout << dist << " ";
}