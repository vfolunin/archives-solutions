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

    Point rotate(double angle) {
        return Point(x * cos(angle) - y * sin(angle), y * cos(angle) + x * sin(angle));
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    double angleTo(const Point &that) const {
        return acos(max(-1.0, min(1.0, dotProduct(that) / (length() * that.length()))));
    }
};

struct Line {
    double a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    static Line LineByVector(const Point &p, const Point &v) {
        return Line(p, p + v);
    }

    Point intersection(const Line &that) const {
        double d = a * that.b - b * that.a;
        double dx = -c * that.b - b * -that.c;
        double dy = a * -that.c - -c * that.a;
        return Point(dx / d, dy / d);
    }
};

void solve() {
    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    Point ab(a, b), ac(a, c);
    double alpha = ab.angleTo(ac);
    Line af = Line::LineByVector(a, ab.rotate(alpha / 3));
    Line ae = Line::LineByVector(a, ab.rotate(alpha * 2 / 3));

    Point ba(b, a), bc(b, c);
    double beta = bc.angleTo(ba);
    Line bd = Line::LineByVector(b, bc.rotate(beta / 3));
    Line bf = Line::LineByVector(b, bc.rotate(beta * 2 / 3));

    Point ca(c, a), cb(c, b);
    double gamma = ca.angleTo(cb);
    Line ce = Line::LineByVector(c, ca.rotate(gamma / 3));
    Line cd = Line::LineByVector(c, ca.rotate(gamma * 2 / 3));

    Point d = bd.intersection(cd);
    Point e = ae.intersection(ce);
    Point f = af.intersection(bf);

    cout << fixed << d.x << " " << d.y << " ";
    cout << e.x << " " << e.y << " ";
    cout << f.x << " " << f.y << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}