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

    int pointCount;
    cin >> pointCount;

    vector<pair<int, int>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    double res = 0;
    for (int i = 0; i < points.size(); i++)
        res = max(res, atan2(points[i].second, points[i].first - points[0].first));
    for (int i = points.size() - 1; i >= 0; i--)
        res = max(res, atan2(points[i].second, points.back().first - points[i].first));

    cout << fixed << res / acos(-1) * 180;
}