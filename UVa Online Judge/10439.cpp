#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9, PI = acos(-1);

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double length() const {
        return hypot(x, y);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    double angleTo(const Point &that) const {
        return acos(max(-1.0, min(1.0, dotProduct(that) / (length() * that.length()))));
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

double gcd(double a, double b) {
    return fabs(b) > 1e-3 ? gcd(b, fmod(a, b)) : a;
}

void solve() {
    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    Line l1 = Line::LineByNormal((a + b) * 0.5, Point(a, b));
    Line l2 = Line::LineByNormal((a + c) * 0.5, Point(a, c));
    Point o = l1.intersection(l2);

    double angle = 2 * PI;
    angle = gcd(angle, Point(o, a).angleTo(Point(o, b)));
    angle = gcd(angle, Point(o, a).angleTo(Point(o, c)));
    angle = gcd(angle, Point(o, b).angleTo(Point(o, c)));

    cout.precision(0);
    cout << fixed << 2 * PI / angle << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}