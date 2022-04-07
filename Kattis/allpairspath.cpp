#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount, edgeCount, queryCount;
    cin >> vertexCount >> edgeCount >> queryCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                if (dist[a][v] != 1e9 && dist[v][b] != 1e9 && dist[a][b] > dist[a][v] + dist[v][b])
                    dist[a][b] = max<int>(dist[a][v] + dist[v][b], -1e9);

    for (int v = 0; v < vertexCount; v++)
        if (dist[v][v] < 0)
            for (int a = 0; a < vertexCount; a++)
                if (dist[a][v] != 1e9)
                    for (int b = 0; b < vertexCount; b++)
                        if (dist[v][b] != 1e9)
                            dist[a][b] = -2e9;

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == 1e9)
            cout << "Impossible\n";
        else if (dist[a][b] == -2e9)
            cout << "-Infinity\n";
        else
            cout << dist[a][b] << "\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}