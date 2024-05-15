#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<long long> dist(graph.size(), 1e18);
    set<pair<long long, int>> q;

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

    int vertexCount;
    cin >> vertexCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;
        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    vector<long long> dist0 = dijkstra(graph, 0);
    int a = max_element(dist0.begin(), dist0.end()) - dist0.begin();
    vector<long long> distA = dijkstra(graph, a);
    long long diameter = *max_element(distA.begin(), distA.end());

    cout << diameter;
}