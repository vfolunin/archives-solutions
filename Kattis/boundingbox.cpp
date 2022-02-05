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

    double angle() const {
        double a = atan2(y, x);
        if (a < -EPS)
            a += 2 * acos(-1.0);
        return a;
    }

    double length() const {
        return sqrt(x * x + y * y);
    }

    double distanceTo(const Point &that) const {
        return Point(*this, that).length();
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    Point orthogonalPoint() const {
        return Point(-y, x);
    }
};


struct Line {
    double a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    static Line LineByVector(const Point &p, const Point &v) {
        return Line(p, p + v);
    }

    static Line LineByNormal(const Point &p, const Point &n) {
        return LineByVector(p, n.orthogonalPoint());
    }

    Point intersection(const Line &that) const {
        double d = a * that.b - b * that.a;
        double dx = -c * that.b - b * -that.c;
        double dy = a * -that.c - -c * that.a;
        return Point(dx / d, dy / d);
    }
};

bool solve() {
    int n;
    Point a, b, c;
    if (!(cin >> n >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y))
        return 0;

    Line l1 = Line::LineByNormal((a + b) * 0.5, { a, b });
    Line l2 = Line::LineByNormal((a + c) * 0.5, { a, c });
    Point o = l1.intersection(l2);

    double r = o.distanceTo(a);
    double startAngle = Point(o, a).angle();
    double angle = 2 * acos(-1) / n;

    double xl = 1e9, xr = -1e9, yl = 1e9, yr = -1e9;
    for (int i = 0; i < n; i++) {
        double x = o.x + r * cos(startAngle + angle * i);
        double y = o.y + r * sin(startAngle + angle * i);
        xl = min(xl, x);
        xr = max(xr, x);
        yl = min(yl, y);
        yr = max(yr, y);
    }

    double res = (xr - xl) * (yr - yl);

    cout.precision(10);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}