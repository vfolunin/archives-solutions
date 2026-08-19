#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("floyd.in", "r", stdin);
    freopen("floyd.out", "w", stdout);
 
    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> dist[a][b];

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++)
            cout << dist[a][b] << " ";
        cout << "\n";
    }
}