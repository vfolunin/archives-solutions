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
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

struct Line {
    double a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x * p2.y - p2.x * p1.y) {}

    Point intersection(const Line &that) const {
        double d = a * that.b - b * that.a;
        double dx = -c * that.b - b * -that.c;
        double dy = a * -that.c - -c * that.a;
        return Point(dx / d, dy / d);
    }
};

void solve() {
    Point a, b, c;
    cin >> a >> b >> c;

    Point d = b + Point(b, c) * (1.0 / 3);
    Point e = c + Point(c, a) * (1.0 / 3);
    Point f = a + Point(a, b) * (1.0 / 3);

    Line ad(a, d), be(b, e), cf(c, f);
    Point p = ad.intersection(be);
    Point q = be.intersection(cf);
    Point r = cf.intersection(ad);

    double sideA = p.distanceTo(q);
    double sideB = q.distanceTo(r);
    double sideC = r.distanceTo(p);
    double semiPerimeter = (sideA + sideB + sideC) / 2;
    double area = sqrt(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC));

    cout.precision(0);
    cout << fixed << area << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}