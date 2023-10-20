#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<long long> dist(graph.size(), 1e18);
    dist[start] = 0;
    set<pair<long long, int>> q = { { dist[start], start } };

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

    return dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, finishCount, start;
    cin >> vertexCount >> edgeCount >> finishCount >> start;
    start--;

    vector<int> finish(finishCount);
    for (int &v : finish) {
        cin >> v;
        v--;
    }

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;

        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    vector<long long> dist = dijkstra(graph, start);

    vector<pair<int, int>> res;
    for (int v : finish)
        res.push_back({ dist[v], v });
    sort(res.begin(), res.end());

    for (auto &[dist, v] : res)
        cout << v + 1 << " " << dist << "\n";
}