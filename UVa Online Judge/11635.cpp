#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int startVertex) {
    vector<int> dist(graph.size(), 1e9);
    dist[startVertex] = 0;
    set<pair<int, int>> q = { { dist[startVertex], startVertex } };

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

vector<int> bfs(vector<vector<int>> &graph, int startVertex) {
    vector<int> dist(graph.size(), 1e9);
    dist[startVertex] = 0;
    queue<int> q;
    q.push(startVertex);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist;
}

bool solve() {
    int vertexCount;
    cin >> vertexCount;
    
    if (!vertexCount)
        return 0;

    int hotelCount;
    cin >> hotelCount;

    vector<int> hotels(hotelCount);
    for (int &x : hotels) {
        cin >> x;
        x--;
    }
    if (find(hotels.begin(), hotels.end(), 0) == hotels.end())
        hotels.push_back(0);
    if (find(hotels.begin(), hotels.end(), vertexCount - 1) == hotels.end())
        hotels.push_back(vertexCount - 1);

    int edgeCount;
    cin >> edgeCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a - 1].push_back({ b - 1, w });
        graph[b - 1].push_back({ a - 1, w });
    }

    vector<vector<int>> hotelGraph(vertexCount);
    for (int i = 0; i < hotels.size(); i++) {
        vector<int> dist = dijkstra(graph, hotels[i]);
        for (int j = i + 1; j < hotels.size(); j++) {
            if (dist[hotels[j]] <= 600) {
                hotelGraph[hotels[i]].push_back(hotels[j]);
                hotelGraph[hotels[j]].push_back(hotels[i]);
            }
        }
    }

    vector<int> dist = bfs(hotelGraph, 0);

    if (dist[vertexCount - 1] != 1e9)
        cout << dist[vertexCount - 1] - 1 << "\n";
    else
        cout << "-1\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}