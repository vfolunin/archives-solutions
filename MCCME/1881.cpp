#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, w;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges) {
        cin >> a >> b >> w;
        a--;
        b--;
    }

    vector<long long> dist(vertexCount, -1e18);
    dist[0] = 0;

    for (int i = 0; i < vertexCount - 1; i++)
        for (auto &[a, b, w] : edges)
            if (dist[a] != -1e18 && dist[b] < dist[a] + w)
                dist[b] = dist[a] + w;

    for (int i = 0; i < vertexCount - 1; i++)
        for (auto &[a, b, w] : edges)
            if (dist[a] != -1e18 && dist[b] < dist[a] + w)
                dist[b] = 1e18;

    if (dist[vertexCount - 1] == -1e18)
        cout << ":(";
    else if (dist[vertexCount - 1] == 1e18)
        cout << ":)";
    else
        cout << dist[vertexCount - 1];
}