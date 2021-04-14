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

    Point(double x, double y) : x(x), y(y) {}
    
    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    bool isCollinearTo(const Point &that) const {
        return fabs(crossProduct(that)) < EPS;
    }
};


struct Line {
    double a, b, c;

    Line(double a, double b, double c) : a(a), b(b), c(c) {}
    
    Point normal() const {
        return Point(a, b);
    }

    double distanceTo(const Point &p) const {
        return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }

    double distanceTo(const Line &that) const {
        if (normal().isCollinearTo(that.normal())) {
            Point p = (fabs(a) < EPS ? Point(0, -c / b) : Point(-c / a, 0));
            return that.distanceTo(p);
        } else
            return 0;
    }

    bool intersectsWith(const Line &that) const {
        return distanceTo(that) < EPS;
    }

    Point intersection(const Line &that) const {
        double d = a * that.b - b * that.a;
        double dx = -c * that.b - b * -that.c;
        double dy = a * -that.c - -c * that.a;
        return Point(dx / d, dy / d);
    }
};

bool solve() {
    double a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    if (!a1 && !b1 && !c1 && !a2 && !b2 && !c2)
        return 0;

    Line l1(a1, b1, -c1), l2(a2, b2, -c2);

    if (l1.intersectsWith(l2)) {
        Point p = l1.intersection(l2);

        cout.precision(2);
        cout << "The fixed point is at " << fixed << p.x << " " << p.y << ".\n";
    } else {
        cout << "No fixed point exists.\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}