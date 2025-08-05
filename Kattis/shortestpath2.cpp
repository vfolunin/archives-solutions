#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> dijkstra(vector<vector<vector<int>>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9);
    dist[start] = 0;
    set<pair<int, int>> q = { { dist[start], start } };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (vector<int> &edge : graph[v]) {
            int candidate;
            if (edge[2])
                candidate = edge[1] + (max(dist[v], edge[1]) - edge[1] + edge[2] - 1) / edge[2] * edge[2] + edge[3];
            else if (dist[v] > edge[1])
                continue;
            else
                candidate = edge[1] + edge[3];

            if (dist[edge[0]] > candidate) {
                q.erase({ dist[edge[0]], edge[0] });
                dist[edge[0]] = candidate;
                q.insert({ dist[edge[0]], edge[0] });
            }
        }
    }

    return dist;
}

bool solve(int test) {
    int vertexCount, edgeCount, queryCount, start;
    cin >> vertexCount >> edgeCount >> queryCount >> start;
    if (!vertexCount)
        return 0;

    vector<vector<vector<int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, startTime, period, weight;
        cin >> a >> b >> startTime >> period >> weight;

        graph[a].push_back({ b, startTime, period, weight });
    }

    vector<int> dist = dijkstra(graph, start);

    if (test)
        cout << "\n";
    for (int i = 0; i < queryCount; i++) {
        int v;
        cin >> v;

        if (dist[v] != 1e9)
            cout << dist[v] << "\n";
        else
            cout << "Impossible\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}