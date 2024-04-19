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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));

    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        dist[a][b] = 0;
        dist[b][a] = min(dist[b][a], 1);
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                if (dist[a][v] != 1e9 && dist[v][b] != 1e9)
                    dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int res = 0;
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            res = max(res, dist[a][b]);

    cout << res;
}