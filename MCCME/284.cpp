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

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator - (const Point &that) const {
        return Point(x - that.x, y - that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    Point setLength(double newLength) const {
        double k = newLength / length();
        return Point(x * k, y * k);
    }

    Point orthogonalPoint() const {
        return Point(-y, x);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }

    friend ostream &operator << (ostream &out, const Point &p) {
        return out << p.x << " " << p.y;
    }
};

struct Line {
    double a, b, c;

    Line() {}

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    static Line LineByVector(const Point &p, const Point &v) {
        return Line(p, p + v);
    }

    Point normal() const {
        return Point(a, b);
    }

    Line orthogonalLine(const Point &p) const {
        return LineByVector(p, normal());
    }

    double distanceTo(const Point &p) const {
        return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }

    Point intersection(const Line &that) const {
        double d = a * that.b - b * that.a;
        double dx = -c * that.b - b * -that.c;
        double dy = a * -that.c - -c * that.a;
        return Point(dx / d, dy / d);
    }

    friend istream &operator >> (istream &in, Line &l) {
        return in >> l.a >> l.b >> l.c;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point o;
    double radius;
    Line l;
    cin >> o >> radius >> l;

    double olDist = l.distanceTo(o);
    if (radius + EPS < olDist) {
        cout << 0;
    } else if (radius <= olDist + EPS) {
        cout << "1\n" << fixed << l.intersection(l.orthogonalLine(o));
    } else {
        Point p = l.intersection(l.orthogonalLine(o));
        double paDist = sqrt(radius * radius - olDist * olDist);
        Point pa = l.normal().orthogonalPoint().setLength(paDist);

        cout << "2\n";
        cout << fixed << p + pa << "\n";
        cout << fixed << p - pa << "\n";
    }
}