#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double prim(vector<double> &x, vector<double> &y) {
    vector<bool> visited(x.size());
    vector<double> dist(x.size(), 1e9);
    dist[0] = 0;

    double mstWeight = 0;

    for (int i = 0; i < x.size(); i++) {
        int nearestV = -1;
        for (int v = 0; v < x.size(); v++)
            if (!visited[v] && (nearestV == -1 || dist[v] < dist[nearestV]))
                nearestV = v;

        visited[nearestV] = true;
        mstWeight += dist[nearestV];

        for (int to = 0; to < x.size(); to++)
            dist[to] = min(dist[to], hypot(x[nearestV] - x[to], y[nearestV] - y[to]));
    }

    return mstWeight;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<double> x(pointCount), y(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i];

    cout.precision(0);
    cout << fixed << prim(x, y);
}