#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> &bonus) {
    vector<int> dist(graph.size(), 1e9);
    vector<int> maxBonus(graph.size());
    dist[0] = 0;
    maxBonus[0] = bonus[0];
    set<pair<int, int>> q = { { 0, 0 } };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                maxBonus[to] = maxBonus[v] + bonus[to];
                q.insert({ dist[to], to });
            } else if (dist[to] == dist[v] + w) {
                maxBonus[to] = max(maxBonus[to], maxBonus[v] + bonus[to]);
            }
        }
    }

    return { dist.back(), maxBonus.back() };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<int> bonus(vertexCount);
    for (int &b : bonus)
        cin >> b;

    int edgeCount;
    cin >> edgeCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    auto [minDist, maxBonus] = dijkstra(graph, bonus);

    if (minDist == 1e9)
        cout << "impossible";
    else
        cout << minDist << " " << maxBonus;
}