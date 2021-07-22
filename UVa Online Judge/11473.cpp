#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int pointCount, treeCount;
    cin >> pointCount >> treeCount;

    vector<pair<double, double>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    vector<double> pDist(pointCount);
    for (int i = 1; i < pointCount; i++)
        pDist[i] = pDist[i - 1] + hypot(points[i].first - points[i - 1].first, points[i].second - points[i - 1].second);

    double treeDist = pDist.back() / (treeCount - 1);

    cout << "Road #" << test << ":\n";
    cout.precision(2);

    for (int i = 0; i < treeCount - 1; i++) {
        double dist = i * treeDist;
        int i2 = upper_bound(pDist.begin(), pDist.end(), dist) - pDist.begin();
        int i1 = i2 - 1;

        auto [x1, y1] = points[i1];
        auto [x2, y2] = points[i2];
        double x = x1 + (dist - pDist[i1]) / (pDist[i2] - pDist[i1]) * (x2 - x1);
        double y = y1 + (dist - pDist[i1]) / (pDist[i2] - pDist[i1]) * (y2 - y1);

        cout << fixed << x << " " << y << "\n";
    }

    cout << fixed << points.back().first << " " << points.back().second << "\n";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}