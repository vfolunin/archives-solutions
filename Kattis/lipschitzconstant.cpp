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

    int pointCount;
    cin >> pointCount;

    vector<pair<double, double>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    sort(points.begin(), points.end());

    double res = 0;
    for (int i = 1; i < points.size(); i++) {
        double num = points[i].second - points[i - 1].second;
        double den = points[i].first - points[i - 1].first;
        res = max(res, abs(num / den));
    }

    cout << fixed << res;
}