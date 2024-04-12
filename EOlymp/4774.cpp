#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    long long x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator < (const Point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }

    long long length2() const {
        return x * x + y * y;
    }

    long long crossProduct(const Point &that) const {
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

    Polygon convexHull() {
        nth_element(points.begin(), points.begin(), points.end());
        sort(points.begin() + 1, points.end(), [&](Point &a, Point &b) {
            Point &o = points[0], oa(o, a), ob(o, b);
            return oa.crossProduct(ob) > 0 || oa.crossProduct(ob) == 0 && oa.length2() < ob.length2();
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
        return { hull };
    }

    friend istream &operator >> (istream &in, Polygon &p) {
        int pointCount;
        in >> pointCount;

        p.points.resize(pointCount);
        for (Point &point : p.points)
            in >> point;

        return in;
    }

    friend ostream &operator << (ostream &out, const Polygon &p) {
        out << p.points.size() << "\n";
        for (const Point &point : p.points)
            out << point << "\n";
        return out;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Polygon polygon;
    cin >> polygon;

    cout << polygon.convexHull();
}