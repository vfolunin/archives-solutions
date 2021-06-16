#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b;
    double t, w;
};

pair<double, vector<int>> dijkstra(vector<vector<Edge>> &graph, int start, int finish, double tLimit) {
    vector<double> dist(graph.size(), 1e9);
    vector<int> pred(graph.size(), -1);
    dist[start] = 0;
    set<pair<double, int>> q = { { dist[start], start } };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[_, to, t, w] : graph[v]) {
            if (t <= tLimit && dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                pred[to] = v;
                q.insert({ dist[to], to });
            }
        }
    }

    vector<int> path;
    if (dist[finish] != 1e9) {
        for (int v = finish; v != -1; v = pred[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
    }

    return { dist[finish], path };
}

bool solve() {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    int start, finish;
    cin >> start >> finish;
    start--;
    finish--;

    vector<vector<Edge>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        double t, w;
        cin >> a >> b >> t >> w;
        a--;
        b--;

        graph[a].push_back({ a, b, t, w });
        graph[b].push_back({ b, a, t, w });
    }

    double l = 0, r = 1e9;
    for (int i = 0; i < 50; i++) {
        double m = (l + r) / 2;
        if (dijkstra(graph, start, finish, m).first == 1e9)
            l = m;
        else
            r = m;
    }
    
    auto [dist, path] = dijkstra(graph, start, finish, r);

    for (int i = 0; i < path.size(); i++)
        cout << path[i] + 1 << (i + 1 < path.size() ? " " : "\n");
    cout.precision(1);
    cout << fixed << dist << " " << r << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}