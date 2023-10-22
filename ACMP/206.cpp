#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int vTime, to, toTime;
};

int dijkstra(vector<vector<Edge>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    set<pair<int, int>> q;

    dist[start] = 0;
    q.insert({ dist[start], start });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == finish)
            return dist[v];

        for (auto &[vTime, to, toTime] : graph[v]) {
            if (dist[v] <= vTime && dist[to] > toTime) {
                q.erase({ dist[to], to });
                dist[to] = toTime;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist[finish] != 1e9 ? dist[finish] : -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, finish, trainCount;
    cin >> vertexCount >> finish >> trainCount;
    finish--;

    vector<vector<Edge>> graph(vertexCount);
    for (int i = 0; i < trainCount; i++) {
        int stopCount;
        cin >> stopCount;

        vector<pair<int, int>> stops(stopCount);
        for (auto &[v, time] : stops) {
            cin >> v >> time;
            v--;
        }

        for (int j = 0; j + 1 < stops.size(); j++)
            graph[stops[j].first].push_back({ stops[j].second, stops[j + 1].first, stops[j + 1].second });
    }

    cout << dijkstra(graph, 0, finish);
}