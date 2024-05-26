#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &graph, int start, int finish) {
    vector<vector<int>> dist(graph.size(), vector<int>(2, 1e9));
    queue<pair<int, int>> q;

    dist[start][0] = 0;
    q.push({ start, 0 });

    while (!q.empty()) {
        auto [v, parity] = q.front();
        q.pop();

        if (v == finish && !parity)
            return dist[v][parity];

        for (int to : graph[v]) {
            if (dist[to][parity ^ 1] > dist[v][parity] + 1) {
                dist[to][parity ^ 1] = dist[v][parity] + 1;
                q.push({ to, parity ^ 1 });
            }
        }
    }

    return -1;
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

    cout << bfs(graph, start, finish);
}