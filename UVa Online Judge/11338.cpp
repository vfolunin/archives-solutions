#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<double> dijkstra(vector<vector<pair<int, double>>> &graph, int start) {
    vector<double> dist(graph.size(), 1e9);
    dist[start] = 0;
    set<pair<double, int>> q = { {dist[start], start} };

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

bool solve() {
    double w, h;
    if (!(cin >> w >> h))
        return 0;

    int pointCount;
    cin >> pointCount;

    vector<pair<double, double>> points(pointCount + 2);
    points[0] = { 0, 0 };
    for (int i = 1; i <= pointCount; i++)
        cin >> points[i].first >> points[i].second;
    points.back() = { w, h };

    vector<vector<pair<int, double>>> graph(points.size());
    for (int a = 0; a < points.size(); a++) {
        for (int b = a + 1; b < points.size(); b++) {
            double dx = points[a].first - points[b].first;
            double dy = points[a].second - points[b].second;
            double dist = hypot(dx, dy);
            if (dist <= 1.5 + 1e-9) {
                graph[a].push_back({ b, dist });
                graph[b].push_back({ a, dist });
            }
        }
    }

    vector<double> dist = dijkstra(graph, 0);
    double maxDist;
    cin >> maxDist;

    cout << (dist.back() <= maxDist + 1e-9 ? "I am lucky!\n" : "Boom!\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}