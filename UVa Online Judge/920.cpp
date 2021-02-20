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

    bool operator < (const Point &that) const {
        return x < that.x;
    }

    double distTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }
};

Point getP(Point &a, Point &b, double y) {
    double x = a.x + (a.y - y) / (a.y - b.y) * (b.x - a.x);
    return { x, y };
}

void solve() {
    int pointCount;
    cin >> pointCount;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;
    sort(points.begin(), points.end());

    double res = 0, h = 0;
    for (int i = pointCount - 2; i >= 0; i--) {
        if (points[i].y <= h)
            continue;
        Point p = getP(points[i], points[i + 1], h);
        res += points[i].distTo(p);
        h = points[i].y;
    }

    cout.precision(2);
    cout << fixed << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}