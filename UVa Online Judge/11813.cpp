#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9);
    dist[start] = 0;
    set<pair<int, int>> q = { {dist[start], start} };

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

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    int pointCount;
    cin >> pointCount;

    vector<int> points(1 + pointCount);
    for (int i = 1; i < points.size(); i++)
        cin >> points[i];

    vector<vector<int>> dist(points.size(), vector<int>(points.size()));
    for (int i = 0; i < points.size(); i++) {
        vector<int> d = dijkstra(graph, points[i]);
        for (int j = i + 1; j < points.size(); j++)
            dist[i][j] = dist[j][i] = d[points[j]];
    }

    vector<int> p(points.size());
    for (int i = 0; i < p.size(); i++)
        p[i] = i;

    int res = 1e9;
    do {
        int len = 0;
        for (int i = 0; i < p.size(); i++)
            len += dist[p[i]][p[(i + 1) % p.size()]];
        res = min(res, len);
    } while (next_permutation(p.begin() + 1, p.end()));

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}