#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double globeDist(double lat1, double lon1, double lat2, double lon2) {
    static const double R = 6378;
    double angle = acos(min(max(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2), -1.0), 1.0));
    return R * angle;
}

bool solve() {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    vector<double> lat(vertexCount), lon(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        cin >> lat[v] >> lon[v];

    static const double F = acos(-1) / 180;
    vector<double> maxDist(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        for (int to = 0; to < vertexCount; to++)
            maxDist[v] = max(maxDist[v], globeDist(lat[v] * F, lon[v] * F, lat[to] * F, lon[to] * F));

    int resV = vertexCount - 1;
    for (int v = vertexCount - 2; v >= 0; v--)
        if (maxDist[v] + 1e-9 < maxDist[resV])
            resV = v;

    cout.precision(2);
    cout << fixed << lat[resV] << " " << lon[resV] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}