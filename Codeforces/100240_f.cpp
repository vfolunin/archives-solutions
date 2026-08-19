#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int toV, toFuel, w;

    bool operator < (const Edge &that) const {
        return w > that.w;
    }
};

int dijkstra(vector<vector<vector<Edge>>> &graph, int maxFuel, int start, int finish) {
    vector<vector<int>> dist(graph.size(), vector<int>(maxFuel + 1, 1e9));
    priority_queue<Edge> q;

    dist[start][0] = 0;
    q.push({ start, 0, 0 });

    while (!q.empty()) {
        auto [v, fuel, d] = q.top();
        q.pop();

        if (d != dist[v][fuel])
            continue;

        if (v == finish)
            return d;

        for (auto &[toV, toFuel, w] : graph[v][fuel]) {
            if (toFuel <= maxFuel && dist[toV][toFuel] > dist[v][fuel] + w) {
                dist[toV][toFuel] = dist[v][fuel] + w;
                q.push({ toV, toFuel, dist[toV][toFuel] });
            }
        }
    }

    return 1e9;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<vector<Edge>>> graph(vertexCount, vector<vector<Edge>>(101));
    for (int v = 0; v < vertexCount; v++) {
        int price;
        cin >> price;
        for (int fuel = 0; fuel < 100; fuel++)
            graph[v][fuel].push_back({ v, fuel + 1, price });
    }

    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        for (int fuel = w; fuel <= 100; fuel++) {
            graph[a][fuel].push_back({ b, fuel - w, 0 });
            graph[b][fuel].push_back({ a, fuel - w, 0 });
        }
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int capacity, start, finish;
        cin >> capacity >> start >> finish;

        int res = dijkstra(graph, capacity, start, finish);

        if (res != 1e9)
            cout << res << "\n";
        else
            cout << "impossible\n";
    }
}