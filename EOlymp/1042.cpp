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
        if (fabs(x - that.x) >= EPS)
            return x < that.x;
        return y + EPS < that.y;
    }

    double length() const {
        return hypot(x, y);
    }

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Polygon {
    vector<Point> points;

    Polygon(int pointCount) : points(pointCount) {}

    Polygon(const vector<Point> &points) : points(points) {}

    double perimeter() const {
        double p = 0;
        for (int i = 0; i < points.size(); i++)
            p += points[i].distanceTo(points[(i + 1) % points.size()]);
        return p;
    }

    Polygon convexHull() {
        nth_element(points.begin(), points.begin(), points.end());
        sort(points.begin() + 1, points.end(), [&](Point &a, Point &b) {
            Point &o = points[0], oa(o, a), ob(o, b);
            return oa.crossProduct(ob) > 0 || oa.crossProduct(ob) == 0 && oa.length() < ob.length();
        });

        vector<Point> hull;
        for (Point &p : points) {
            while (hull.size() >= 2) {
                Point &a = hull[hull.size() - 2], &b = hull[hull.size() - 1];
                Point ab(a, b), ap(a, p);
                if (ab.crossProduct(ap) <= 0)
                    hull.pop_back();
                else
                    break;
            }
            hull.push_back(p);
        }

        return hull;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    double radius;
    cin >> pointCount >> radius;

    Polygon polygon(pointCount);
    for (Point &point : polygon.points)
        cin >> point;

    cout.precision(2);
    cout << fixed << polygon.convexHull().perimeter() + 2 * acos(-1) * radius;
}