#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish) {
    vector<long long> dist(graph.size(), 1e9);
    dist[start] = 0;
    set<pair<long long, int>> q = { { dist[start], start } };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, weight] : graph[v]) {
            if (dist[to] > dist[v] + weight) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + weight;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist[finish];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, start, finish;
    cin >> vertexCount >> start >> finish;
    start--;
    finish--;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;

        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    cout << dijkstra(graph, start, finish);
}