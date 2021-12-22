#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    vector<vector<double>> dist(vertexCount, vector<double>(vertexCount));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 1;

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        double w;
        cin >> a >> b >> w;
        a--;
        b--;
        w /= 100;
        dist[a][b] = max(dist[a][b], w);
        dist[b][a] = max(dist[b][a], w);
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = max(dist[a][b], dist[a][v] * dist[v][b]);

    cout << fixed << dist[0][vertexCount - 1] * 100 << " percent\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}