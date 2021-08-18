#include <iostream>
#include <algorithm>
#include <cmath>
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

    vector<double> x(vertexCount), y(vertexCount);
    for (int i = 0; i < vertexCount; i++)
        cin >> x[i] >> y[i];

    vector<vector<double>> dist(vertexCount, vector<double>(vertexCount, 1e9));

    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    set<pair<int, int>> edges;
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a > b)
            swap(a, b);
        edges.insert({ a, b });
        dist[a][b] = hypot(x[a] - x[b], y[a] - y[b]);
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int bestA = -1, bestB = -1;
    double bestSum, bestW;
    for (int a = 0; a < vertexCount; a++) {
        for (int b = a + 1; b < vertexCount; b++) {
            if (edges.count({ a, b }))
                continue;
            double w = hypot(x[a] - x[b], y[a] - y[b]), curSum = 0;
            for (int va = 0; va < vertexCount; va++) {
                for (int vb = va + 1; vb < vertexCount; vb++) {
                    double d1 = dist[va][vb];
                    double d2 = min(d1, min(dist[va][a] + dist[b][vb], dist[va][b] + dist[a][vb]) + w);
                    curSum += d1 - d2;
                }
            }
            if (bestA == -1 || bestSum < curSum || bestSum == curSum && bestW > w) {
                bestA = a;
                bestB = b;
                bestSum = curSum;
                bestW = w;
            }
        }
    }

    if (bestA == -1)
        cout << "No road required\n";
    else
        cout << bestA + 1 << " " << bestB + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}