#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double f(vector<pair<double, double>> &points, double cx) {
    double res = 0;
    for (auto &[x, y] : points)
        res = max(res, (x - cx) * (x - cx) + y * y);
    return res;
}

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<pair<double, double>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    double l = -1e6, r = 1e6;
    for (int i = 0; i < 300; i++) {
        double m1 = l + (r - l) / 3, f1 = f(points, m1);
        double m2 = r - (r - l) / 3, f2 = f(points, m2);
        if (f1 < f2)
            r = m2;
        else
            l = m1;
    }

    cout << fixed << l << " " << sqrt(f(points, l)) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}