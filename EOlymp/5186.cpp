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

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    Point setLength(double newLength) const {
        double k = newLength / length();
        return Point(x * k, y * k);
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

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    Point intersection(const Line &that) const {
        double d = a * that.b - b * that.a;
        double dx = -c * that.b - b * -that.c;
        double dy = a * -that.c - -c * that.a;
        return Point(dx / d, dy / d);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point a, b, c;
    cin >> a >> b >> c;

    Point b1 = a + Point(a, b).setLength(1);
    Point c1 = a + Point(a, c).setLength(1);
    Point p1 = b1 + Point(b1, c1) * 0.5;

    Point a2 = b + Point(b, a).setLength(1);
    Point c2 = b + Point(b, c).setLength(1);
    Point p2 = a2 + Point(a2, c2) * 0.5;

    cout << fixed << Line(a, p1).intersection(Line(b, p2));
}