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

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> dist[a][b];

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                if (dist[a][v] != -1e9 && dist[v][b] != -1e9 && dist[a][b] > dist[a][v] + dist[v][b])
                    dist[a][b] = max<int>(dist[a][v] + dist[v][b], -1e9);

    for (int v = 0; v < vertexCount; v++) {
        if (dist[v][v] < 0) {
            cout << -1;
            return 0;
        }
    }

    int res = 1e9;
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            if (a != b)
                res = min(res, dist[a][b]);
    cout << res;
}