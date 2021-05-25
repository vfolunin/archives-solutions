#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<vector<int>, vector<int>> bfs(vector<vector<int>> &graph, int v) {
    vector<int> dist(graph.size(), -1), pred(graph.size(), -1);
    queue<int> q;

    dist[v] = 0;
    q.push(v);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                pred[to] = v;
                q.push(to);
            }
        }
    }

    return { dist, pred };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    auto [dist, pred] = bfs(graph, 0);

    if (dist.back() == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> path;
        for (int v = vertexCount - 1; v != -1; v = pred[v])
            path.push_back(v);
        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for (int v : path)
            cout << v + 1 << " ";
    }
}