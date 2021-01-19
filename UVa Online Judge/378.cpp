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

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    bool isCollinearTo(const Point &that) const {
        return fabs(crossProduct(that)) < EPS;
    }
};

struct Line {
    double a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

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

void solve() {
    Point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    
    Line ab(a, b), cd(c, d);
    if (!ab.intersectsWith(cd)) {
        cout << "NONE\n";
    } else if (ab.normal().isCollinearTo(cd.normal())) {
        cout << "LINE\n";
    } else {
        Point p = ab.intersection(cd);
        cout << "POINT " << p.x << " " << p.y << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << fixed;
    cout.precision(2);

    cout << "INTERSECTING LINES OUTPUT\n";
    for (int i = 0; i < n; i++)
        solve();
    cout << "END OF OUTPUT\n";
}