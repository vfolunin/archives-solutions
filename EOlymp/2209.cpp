#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 2e9);
    set<pair<int, int>> q;

    dist[start] = 0;
    q.insert({ dist[start], start });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == finish)
            return dist[v];

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    return 2e9;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int finish, wUp, wDown, wIn, wOut, liftCount;
    cin >> finish >> wUp >> wDown >> wIn >> wOut >> liftCount;
    
    vector<vector<pair<int, int>>> graph(1e6 + liftCount);
    for (int v = 0; v + 1 < 1e6; v++) {
        graph[v].push_back({ v + 1, wUp });
        graph[v + 1].push_back({ v, wDown });
    }

    for (int i = 0; i < liftCount; i++) {
        int size;
        cin >> size;
        for (int j = 0; j < size; j++) {
            int v;
            cin >> v;
            v--;

            graph[v].push_back({ 1e6 + i, wIn });
            graph[1e6 + i].push_back({ v, wOut });
        }
    }

    cout << dijkstra(graph, 0, finish - 1);
}