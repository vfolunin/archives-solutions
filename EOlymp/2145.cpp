#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

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

    Line(double a, double b, double c) : a(a), b(b), c(c) {}

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    static Line LineByVector(const Point &p, const Point &v) {
        return Line(p, p + v);
    }

    static Line LineByNormal(const Point &p, const Point &n) {
        return LineByVector(p, n.orthogonalPoint());
    }

    Point point() const {
        return a ? Point(-c / a, 0) : Point(0, -c / b);
    }

    Point normal() const {
        return Point(a, b);
    }

    Line parallelLine(const Point &p) const {
        return LineByNormal(p, normal());
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

    Line line;
    int dist;
    cin >> line >> dist;

    cout << fixed << line.parallelLine(line.point() + line.normal().setLength(dist)) << "\n";
    cout << line.parallelLine(line.point() + line.normal().setLength(-dist));
}