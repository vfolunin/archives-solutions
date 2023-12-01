#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9);
    set<pair<int, int>> q;

    dist[start] = 0;
    q.insert({ dist[start], start });

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

    int vertexCount, finishCount, edgeCount;
    cin >> vertexCount >> finishCount >> edgeCount;

    vector<int> finish(finishCount);
    for (int &v : finish) {
        cin >> v;
        v--;
    }

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;
        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    int start;
    cin >> start;
    start--;

    vector<int> dist = dijkstra(graph, start);
    int res = 0;
    for (int v : finish)
        res = max(res, dist[v]);

    if (res < 1e9)
        cout << "The good sponsor!\n" << res;
    else
        cout << "It is not fault of sponsor...";
}