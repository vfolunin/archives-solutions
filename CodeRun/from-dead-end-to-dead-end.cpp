#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &graph) {
    vector<int> dist(graph.size(), 1e9);
    queue<pair<int, int>> q;

    for (int v = 0; v < graph.size(); v++) {
        if (graph[v].size() == 1) {
            dist[v] = 0;
            q.push({ v, -1 });
        }
    }

    while (1) {
        auto [v, parent] = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] == 1e9) {
                dist[to] = dist[v] + 1;
                q.push({ to, v });
            } else if (to != parent) {
                return dist[v] + 1 + dist[to];
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << bfs(graph);
}