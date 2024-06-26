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

    vector<vector<double>> dist(vertexCount, vector<double>(vertexCount));
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        dist[a][b] = dist[b][a] = w / 100.0;
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = max(dist[a][b], dist[a][v] * dist[v][b]);

    cout << fixed << dist[0][vertexCount - 1] * 100 << " percent";

}