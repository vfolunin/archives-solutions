#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator < (const Point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }

    bool operator == (const Point &that) const {
        return x == that.x && y == that.y;
    }

    double length() const {
        return hypot(x, y);
    }

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    int crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }

    friend ostream &operator << (ostream &out, const Point &p) {
        return out << p.x << " " << p.y;
    }
};

struct Polygon {
    vector<Point> points;

    void addPoint(const Point &p) {
        points.push_back(p);
    }

    Polygon convexHull() {
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());

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

        Polygon res;
        for (Point &p : hull)
            res.addPoint(p);
        return res;
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

    Polygon hull = polygon.convexHull();
    if (pointCount % 2)
        reverse(hull.points.begin(), hull.points.end());

    cout << hull.points.size() << "\n";
    for (Point &p : hull.points)
        cout << p << "\n";
}