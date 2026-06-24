#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int a = 0; a < graph.size(); a++) {
        for (int b = a + 1; b < graph.size(); b++) {
            int weight;
            cin >> weight;

            graph[a].push_back({ b, weight });
        }
    }

    vector<int> dist(vertexCount, 1e9), from(vertexCount, -1);
    dist[0] = 0;

    for (int v = 0; v < graph.size(); v++) {
        for (auto &[to, weight] : graph[v]) {
            if (dist[to] > dist[v] + weight) {
                dist[to] = dist[v] + weight;
                from[to] = v;
            }
        }
    }

    vector<int> path;
    for (int v = vertexCount - 1; v != -1; v = from[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    for (int v : path)
        cout << v + 1 << " ";
    cout << "\n" << dist.back();
}