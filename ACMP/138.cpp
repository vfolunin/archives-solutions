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

vector<int> fordBellman(int vertexCount, vector<Edge> &edges, int start) {
    vector<int> dist(vertexCount, 3e4);
    dist[start] = 0;

    for (int i = 0; i < vertexCount - 1; i++)
        for (auto &[a, b, w] : edges)
            if (dist[a] != 3e4 && dist[b] > dist[a] + w)
                dist[b] = dist[a] + w;

    return dist;
}

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

    vector<int> dist = fordBellman(vertexCount, edges, 0);

    for (int d : dist)
        cout << d << " ";
}