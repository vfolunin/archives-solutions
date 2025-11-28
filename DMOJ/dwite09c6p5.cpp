#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int dijkstra(unordered_map<string, unordered_map<string, int>> &graph, const string &start, const string &finish) {
    unordered_map<string, int> dist;
    set<pair<int, string>> q;

    dist[start] = 0;
    q.insert({ dist[start], start });

    while (!q.empty()) {
        string v = q.begin()->second;
        q.erase(q.begin());

        if (v == finish)
            return dist[v];

        for (auto &[to, weight] : graph[v]) {
            if (!dist.count(to) || dist[to] > dist[v] + weight) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + weight;
                q.insert({ dist[to], to });
            }
        }
    }

    return 1e9;
}

bool solve() {
    int edgeCount;
    if (!(cin >> edgeCount))
        return 0;

    unordered_map<string, unordered_map<string, int>> graph;
    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        int weight;
        cin >> a >> b >> weight;

        graph[a][b] = weight;
    }

    cout << dijkstra(graph, "YYZ", "SEA") << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}