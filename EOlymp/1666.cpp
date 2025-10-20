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

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator < (const Point &that) const {
        return y < that.y || y == that.y && x < that.x;
    }

    double length() const {
        return hypot(x, y);
    }

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

bool eraseConvexHull(vector<Point> &points) {
    if (points.size() < 3)
        return 0;

    nth_element(points.begin(), points.begin(), points.end());
    sort(points.begin() + 1, points.end(), [&](Point &a, Point &b) {
        Point &o = points[0], oa(o, a), ob(o, b);
        return oa.crossProduct(ob) > 0 || oa.crossProduct(ob) == 0 && oa.length() < ob.length();
    });

    vector<Point> hull, nextPoints;
    for (Point &p : points) {
        while (hull.size() >= 2) {
            Point &a = hull[hull.size() - 2], &b = hull[hull.size() - 1];
            Point ab(a, b), ap(a, p);
            if (ab.crossProduct(ap) <= 0) {
                nextPoints.push_back(hull.back());
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.push_back(p);
    }

    points.swap(nextPoints);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<Point> points(pointCount);
    for (Point &point : points)
        cin >> point;

    int iterCount = 0;
    while (eraseConvexHull(points))
        iterCount++;

    cout << points.size() << " " << iterCount;
}