#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dijkstra(vector<vector<vector<int>>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    dist[start] = 0;
    set<pair<int, int>> q = { { dist[start], start } };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == finish)
            return dist[finish];

        for (vector<int> &edge : graph[v]) {
            if (dist[v] <= edge[0] && dist[edge[2]] > edge[1]) {
                q.erase({ dist[edge[2]], edge[2] });
                dist[edge[2]] = edge[1];
                q.insert({ dist[edge[2]], edge[2] });
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, start, finish, edgeCount;
    cin >> vertexCount >> start >> finish >> edgeCount;
    start--;
    finish--;

    vector<vector<vector<int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, ta, b, tb;
        cin >> a >> ta >> b >> tb;
        a--;
        b--;

        graph[a].push_back({ ta, tb, b });
    }

    cout << dijkstra(graph, start, finish);
}