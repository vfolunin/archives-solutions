#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount)
        return 0;
    
    vector<vector<double>> dist(vertexCount, vector<double>(vertexCount, 1e9));

    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        dist[a][b] = w;
        dist[b][a] = -w;
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    for (int v = 0; v < vertexCount; v++) {
        if (dist[v][v] < 0) {
            cout << "Y\n";
            return 1;
        }
    }

    cout << "N\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}