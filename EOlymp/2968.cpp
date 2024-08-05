#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b;
    long long weight;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, start;
    cin >> vertexCount >> edgeCount >> start;
    start--;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, weight] : edges) {
        cin >> a >> b >> weight;
        a--;
        b--;
    }

    const long long INF = 4e18;
    vector<long long> dist(vertexCount, INF);
    dist[start] = 0;

    for (int i = 0; i < vertexCount - 1; i++)
        for (auto [a, b, weight] : edges)
            if (dist[a] != INF && dist[b] > dist[a] + weight)
                dist[b] = max(dist[a] + weight, -INF);

    for (int i = 0; i < vertexCount - 1; i++)
        for (auto [a, b, weight] : edges)
            if (dist[a] != INF && dist[b] > dist[a] + weight)
                dist[b] = -INF;

    for (int v = 0; v < vertexCount; v++) {
        if (dist[v] == INF)
            cout << "*\n";
        else if (dist[v] == -INF)
            cout << "-\n";
        else
            cout << dist[v] << "\n";
    }
}