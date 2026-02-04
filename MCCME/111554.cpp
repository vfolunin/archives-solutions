#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs01(vector<vector<pair<int, int>>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    deque<int> q;

    dist[start] = 0;
    q.push_back(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();

        if (v == finish)
            return dist[v];

        for (auto &[to, weight] : graph[v]) {
            if (weight && dist[to] > dist[v] + weight) {
                dist[to] = dist[v] + weight;
                q.push_back(to);
            } else if (!weight && dist[to] > dist[v]) {
                dist[to] = dist[v];
                q.push_front(to);
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back({ b, 0 });
        graph[b].push_back({ a, 1 });
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int start, finish;
        cin >> start >> finish;
        start--;
        finish--;

        cout << bfs01(graph, start, finish) << "\n";
    }
}