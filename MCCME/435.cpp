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

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
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

    friend istream &operator >> (istream &in, Line &l) {
        return in >> l.a >> l.b >> l.c;
    }

    friend ostream &operator << (ostream &out, const Line &l) {
        return out << l.a << " " << l.b << " " << l.c;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Line l;
    Point p;
    cin >> l >> p;

    cout << fixed << l.orthogonalLine(p);
}