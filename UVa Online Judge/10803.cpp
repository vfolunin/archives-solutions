#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int pointCount;
    cin >> pointCount;

    vector<pair<int, int>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    vector<vector<double>> dist(pointCount, vector<double>(pointCount, 1e9));
    for (int a = 0; a < pointCount; a++) {
        for (int b = 0; b < pointCount; b++) {
            double dx = points[a].first - points[b].first;
            double dy = points[a].second - points[b].second;
            double d = hypot(dx, dy);
            if (d <= 10 + 1e-9)
                dist[a][b] = d;
        }
    }

    for (int v = 0; v < pointCount; v++)
        for (int a = 0; a < pointCount; a++)
            for (int b = 0; b < pointCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    double res = 0;
    for (int a = 0; a < pointCount; a++)
        for (int b = 0; b < pointCount; b++)
            res = max(res, dist[a][b]);

    cout << "Case #" << test << ":\n";
    if (res < 1e9) {
        cout.precision(4);
        cout << fixed << res << "\n\n";
    } else {
        cout << "Send Kurdy\n\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}