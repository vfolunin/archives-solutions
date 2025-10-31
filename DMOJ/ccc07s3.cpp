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

    return 1e9;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int edgeCount;
    cin >> edgeCount;

    vector<vector<int>> graph(1e5);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    while (1) {
        int a, b;
        cin >> a >> b;

        if (!a && !b)
            return 0;

        int ab = bfs(graph, a, b);
        int ba = bfs(graph, b, a);

        if (ab != 1e9 && ba != 1e9)
            cout << "Yes " << ab - 1 << "\n";
        else
            cout << "No\n";
    }
}