#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    dist[start] = 0;
    set<pair<int, int>> q = { {dist[start], start} };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist[finish];
}

bool solve(int test) {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    vector<vector<pair<int, int>>> graph(vertexCount * 2);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a * 2].push_back({ b * 2 + 1, w });
        graph[a * 2 + 1].push_back({ b * 2, w });
        graph[b * 2].push_back({ a * 2 + 1, w });
        graph[b * 2 + 1].push_back({ a * 2, w });
    }

    int res = dijkstra(graph, 0, (vertexCount - 1) * 2);

    cout << "Set #" << test << "\n";
    if (res == 1e9)
        cout << "?\n";
    else
        cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}