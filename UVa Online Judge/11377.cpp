#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish) {
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

    return dist[finish];
}

void solve(int test) {
    int vertexCount, edgeCount, airportCount;
    cin >> vertexCount >> edgeCount >> airportCount;

    vector<vector<pair<int, int>>> graph(vertexCount * 2);

    for (int i = 0; i < airportCount; i++) {
        int v;
        cin >> v;
        v--;
        graph[v].push_back({ vertexCount + v, 0 });
    }
    for (int v = 0; v < vertexCount; v++)
        if (graph[v].empty())
            graph[v].push_back({ vertexCount + v, 1 });

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[vertexCount + a].push_back({ b, 0 });
        graph[vertexCount + b].push_back({ a, 0 });
    }

    int queryCount;
    cin >> queryCount;

    cout << "Case " << test << ":\n";
    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int res = a == b ? 0 : dijkstra(graph, a, vertexCount + b);
        cout << (res != 1e9 ? res : -1) << "\n";
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}