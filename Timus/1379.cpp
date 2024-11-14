#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<vector<vector<int>>> &graph, int mass) {
    const long long INF = 1LL << 60;
    vector<long long> dist(graph.size(), INF);
    set<pair<int, int>> q;

    dist[0] = 0;
    q.insert({ dist[0], 0 });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &edge : graph[v]) {
            int to = edge[0], w = edge[1], limit = edge[2];
            if (mass <= limit && dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist.back() <= 1440;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<vector<int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w, limit;
        cin >> a >> b >> w >> limit;
        a--;
        b--;
        graph[a].push_back({ b, w, limit });
        graph[b].push_back({ a, w, limit });
    }

    int l = 0, r = 1e7 + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(graph, 3e6 + m * 100))
            l = m;
        else
            r = m;
    }

    cout << l;
}