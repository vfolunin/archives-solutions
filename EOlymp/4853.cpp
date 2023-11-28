#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void bfs(vector<vector<int>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    vector<int> from(graph.size(), -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == finish) {
            cout << dist[v] << "\n";

            vector<int> path;
            for (int v = finish; v != -1; v = from[v])
                path.push_back(v);
            reverse(path.begin(), path.end());

            for (int v : path)
                cout << v + 1 << " ";
            return;
        }

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }

    cout << -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, start, finish;
    cin >> vertexCount >> edgeCount >> start >> finish;
    start--;
    finish--;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(graph, start, finish);
}