#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }
};

double rec(int mask, int last, vector<Point> &points, vector<vector<double>> &memo) {
    double &res = memo[mask][last];
    if (res >= -1e-9)
        return res;

    res = 1e9;
    for (int prevLast = 0; prevLast < points.size(); prevLast++) {
        if (prevLast == last || !(mask & (1 << prevLast)))
            continue;
        res = min(res, rec(mask ^ (1 << last), prevLast, points, memo) + points[prevLast].distanceTo(points[last]));
    }
    return res;
}

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    Point start;
    cin >> start.x >> start.y;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    vector<vector<double>> memo(1 << pointCount, vector<double>(pointCount, -1));
    for (int last = 0; last < pointCount; last++)
        memo[1 << last][last] = start.distanceTo(points[last]);

    double res = 1e9;
    for (int last = 0; last < pointCount; last++)
        res = min(res, rec((1 << pointCount) - 1, last, points, memo) + points[last].distanceTo(start));

    cout.precision(2);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}