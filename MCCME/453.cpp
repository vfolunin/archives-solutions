#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Polygon {
    vector<Point> points;

    void addPoint(const Point &p) {
        points.push_back(p);
    }

    double maxDist(const Point &p) {
        double res = 0;
        for (Point &to : points)
            res = max(res, p.distanceTo(to));
        return res;
    }

    pair<double, double> findX(double y) {
        double l = -1e9, r = 1e9;
        for (int i = 0; i < 300; i++) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            double radius1 = maxDist(Point(m1, y));
            double radius2 = maxDist(Point(m2, y));
            if (radius1 < radius2)
                r = m2;
            else
                l = m1;
        }
        return { l, maxDist(Point(l, y)) };
    }

    pair<Point, double> circumcircle() {
        double l = -1e9, r = 1e9;
        for (int i = 0; i < 300; i++) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            auto [x1, radius1] = findX(m1);
            auto [x2, radius2] = findX(m2);
            if (radius1 < radius2)
                r = m2;
            else
                l = m1;
        }
        auto [x, radius] = findX(l);
        return { Point(x, l), radius };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    Polygon polygon;
    for (int i = 0; i < pointCount; i++) {
        Point p;
        cin >> p;
        polygon.addPoint(p);
    }

    auto [center, radius] = polygon.circumcircle();

    cout << fixed << center.x << " " << center.y << " " << radius;
}