#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    Point(double x, double y) : x(x), y(y) {}

    double length() const {
        return hypot(x, y);
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point setLength(double newLength) const {
        double k = newLength / length();
        return Point(x * k, y * k);
    }

    Point orthogonalPoint() const {
        return Point(-y, x);
    }
};

struct Line {
    double a, b, c;

    Line() {}

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    static Line LineByVector(const Point &p, const Point &v) {
        return Line(p, p + v);
    }

    static Line LineByNormal(const Point &p, const Point &n) {
        return LineByVector(p, n.orthogonalPoint());
    }

    Point normal() const {
        return Point(a, b);
    }

    Line parallelLine(double distance) const {
        Point p = (fabs(a) < EPS ? Point(0, -c / b) : Point(-c / a, 0));
        Point p1 = p + normal().setLength(distance);
        return LineByNormal(p1, normal());
    }

    friend istream &operator >> (istream &in, Line &l) {
        return in >> l.a >> l.b >> l.c;
    }

    friend ostream &operator << (ostream &out, const Line &l) {
        return cout << l.a << " " << l.b << " " << l.c;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Line l;
    double dist;
    cin >> l >> dist;

    cout << fixed << l.parallelLine(dist);
}