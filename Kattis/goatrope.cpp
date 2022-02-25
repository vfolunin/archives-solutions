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

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double length() const {
        return hypot(x, y);
    }

    double distanceTo(const Point &that) const {
        return Point(*this, that).length();
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }
};

istream &operator >> (istream &in, Point &p) {
    return in >> p.x >> p.y;
}

struct Segment {
    Point p1, p2;
    double a, b, c;

    Segment(const Point &p1, const Point &p2) : p1(p1), p2(p2), a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    double distanceTo(const Point &p) const {
        if (Point(p1, p).dotProduct(Point(p1, p2)) >= -EPS && Point(p2, p).dotProduct(Point(p2, p1)) >= -EPS)
            return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
        else
            return min(p1.distanceTo(p), p2.distanceTo(p));
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point o, a, c;
    cin >> o >> a >> c;

    Point b(a.x, c.y), d(c.x, a.y);

    double res = Segment(a, b).distanceTo(o);
    res = min(res, Segment(b, c).distanceTo(o));
    res = min(res, Segment(c, d).distanceTo(o));
    res = min(res, Segment(d, a).distanceTo(o));

    cout << fixed << res;
}