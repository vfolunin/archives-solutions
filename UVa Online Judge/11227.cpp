#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator < (const Point &that) const {
        return x + EPS < that.x || fabs(x - that.x) < EPS && y + EPS < that.y;
    }

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    bool isCollinearTo(const Point &that) const {
        return fabs(crossProduct(that)) < EPS;
    }
};

void solve(int test) {
    int pointCount;
    cin >> pointCount;

    set<Point> pointSet;
    for (int i = 0; i < pointCount; i++) {
        Point p;
        cin >> p.x >> p.y;
        pointSet.insert(p);
    }

    cout << "Data set #" << test << " contains ";
    if (pointSet.size() == 1) {
        cout << "a single gnu.\n";
        return;
    }

    vector<Point> points(pointSet.begin(), pointSet.end());
    int res = 2;

    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            Point vec(points[i], points[j]);
            int cur = 0;
            for (Point &p : points)
                cur += vec.isCollinearTo(Point(points[i], p));
            res = max(res, cur);
        }
    }

    cout << pointSet.size() << " gnus, out of which a maximum of " << res << " are aligned.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}