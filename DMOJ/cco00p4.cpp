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

    int vertexCount, edgeCount, queryCount;
    cin >> vertexCount >> edgeCount >> queryCount;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;

        dist[a][b] = dist[b][a] = min(dist[a][b], weight);
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        cout << dist[a][b] << "\n";
    }
}