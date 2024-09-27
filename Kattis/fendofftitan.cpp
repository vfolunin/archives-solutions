#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dijkstra(vector<vector<pair<int, vector<int>>>> &graph, int start, int finish) {
    vector<vector<long long>> dist(graph.size(), vector<long long>(3, 1e18));
    set<pair<vector<long long>, int>> q;

    dist[start].assign(3, 0);
    q.insert({ dist[start], start });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == finish) {
            cout << dist[v][2] << " " << dist[v][1] << " " << dist[v][0];
            return;
        }

        for (auto &[to, w] : graph[v]) {
            vector<long long> d(3);
            for (int i = 0; i < d.size(); i++)
                d[i] = dist[v][i] + w[i];

            if (dist[to] > d) {
                q.erase({ dist[to], to });
                dist[to] = d;
                q.insert({ dist[to], to });
            }
        }
    }

    cout << "IMPOSSIBLE";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, start, finish;
    cin >> vertexCount >> edgeCount >> start >> finish;
    start--;
    finish--;

    vector<vector<pair<int, vector<int>>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight, type;
        cin >> a >> b >> weight >> type;
        a--;
        b--;

        graph[a].push_back({ b, { type == 2, type == 1, weight } });
        graph[b].push_back({ a, { type == 2, type == 1, weight } });
    }

    dijkstra(graph, start, finish);
}