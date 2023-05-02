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

    Point operator + (const Point &that) {
        return Point(x + that.x, y + that.y);
    }

    Point operator - (const Point &that) {
        return Point(x - that.x, y - that.y);
    }

    Point operator * (double k) {
        return Point(x * k, y * k);
    }

    double length() {
        return hypot(x, y);
    }

    Point setLength(double newLength) {
        double k = newLength / length();
        return Point(x * k, y * k);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Line {
    double a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x * p2.y - p2.x * p1.y) {}

    friend ostream &operator << (ostream &out, const Line &l) {
        return out << l.a << " " << l.b << " " << l.c;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point a, b, c;
    cin >> a >> b >> c;

    b = a + Point(a, b).setLength(1);
    c = a + Point(a, c).setLength(1);
    Point d = b + (c - b) * 0.5;

    cout << fixed << Line(a, d);
}