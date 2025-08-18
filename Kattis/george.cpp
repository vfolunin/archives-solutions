#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Edge {
    int weight, lockStart, lockFinish;
};

int dijkstra(vector<unordered_map<int, Edge>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    set<pair<int, int>> q;

    dist[start] = 0;
    q.insert({ dist[start], start });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == finish)
            return dist[v];

        for (auto &[to, edge] : graph[v]) {
            int toDist = dist[v] + edge.weight;
            if (edge.lockStart <= dist[v] && dist[v] < edge.lockFinish)
                toDist = edge.lockFinish + edge.weight;

            if (dist[to] > toDist) {
                q.erase({ dist[to], to });
                dist[to] = toDist;
                q.insert({ dist[to], to });
            }
        }
    }

    return 1e9;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int vertexCount, edgeCount, start, finish, startTime, pathSize;
    cin >> vertexCount >> edgeCount >> start >> finish >> startTime >> pathSize;
    start--;
    finish--;

    vector<int> path(pathSize);
    for (int &v : path) {
        cin >> v;
        v--;
    }

    vector<unordered_map<int, Edge>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;

        graph[a][b] = graph[b][a] = { weight, (int)-1e9, (int)-1e9};
    }

    for (int i = 0, time = -startTime; i + 1 < path.size(); i++) {
        graph[path[i]][path[i + 1]].lockStart = graph[path[i + 1]][path[i]].lockStart = time;
        time += graph[path[i]][path[i + 1]].weight;
        graph[path[i]][path[i + 1]].lockFinish = graph[path[i + 1]][path[i]].lockFinish = time;
    }

    cout << dijkstra(graph, start, finish);
}