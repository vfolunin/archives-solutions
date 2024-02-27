#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, weight;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, iterCount, startVertex, finishVertex;
    cin >> vertexCount >> edgeCount >> iterCount >> startVertex >> finishVertex;
    startVertex--;
    finishVertex--;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, weight] : edges) {
        cin >> a >> b >> weight;
        a--;
        b--;
    }

    vector<vector<int>> dist(2, vector<int>(vertexCount, 1e9));
    dist[1][startVertex] = 0;

    for (int i = 0; i < (vertexCount - 1, iterCount); i++) {
        dist[0] = dist[1];
        for (auto [a, b, weight] : edges)
            dist[1][b] = min(dist[1][b], dist[0][a] + weight);
    }

    cout << (dist[1][finishVertex] != 1e9 ? dist[1][finishVertex] : -1);
}