#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    if (vertexCount < 0)
        return 0;
    vertexCount += 2;

    vector<int> x(vertexCount), y(vertexCount), z(vertexCount), r(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        cin >> x[i] >> y[i] >> z[i];
        if (i + 2 < vertexCount)
            cin >> r[i];
    }

    vector<vector<double>> dist(vertexCount, vector<double>(vertexCount, 1e9));

    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            dist[a][b] = max(0.0, hypot(hypot(x[a] - x[b], y[a] - y[b]), z[a] - z[b]) - r[a] - r[b]);

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    cout.precision(0);
    cout << "Cheese " << test << ": Travel time = " << fixed << dist[vertexCount - 2][vertexCount - 1] * 10 << " sec\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}