#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator * (double k) const {
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

    Line l;
    Point p;
    cin >> l >> p;

    Point o = l.intersection(l.orthogonalLine(p));

    cout << fixed << p + Point(p, o) * 2;
}