#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    // simple nearest neighbour algorithm

    int vertexCount;
    cin >> vertexCount;

    vector<double> x(vertexCount), y(vertexCount);
    for (int i = 0; i < vertexCount; i++)
        cin >> x[i] >> y[i];

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = a + 1; b < vertexCount; b++)
            dist[a][b] = dist[b][a] = hypot(x[a] - x[b], y[a] - y[b]);

    vector<int> path = { 0 };
    vector<int> visited(vertexCount);
    visited[0] = 1;

    for (int i = 1; i < vertexCount; i++) {
        int nearestV = -1;
        for (int v = 0; v < vertexCount; v++)
            if (!visited[v] && (nearestV == -1 || dist[path.back()][nearestV] > dist[path.back()][v]))
                nearestV = v;

        visited[nearestV] = 1;
        path.push_back(nearestV);
    }

    for (int v : path)
        cout << v << "\n";
}