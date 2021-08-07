#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-2;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator != (const Point &that) const {
        return fabs(x - that.x) >= EPS || fabs(y - that.y) >= EPS;
    }

    double length() const {
        return sqrt(x * x + y * y);
    }

    double distanceTo(const Point &that) const {
        return Point(*this, that).length();
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

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

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    Point normal() const {
        return Point(a, b);
    }

    int side(const Point &p) const {
        double r = a * p.x + b * p.y + c;
        if (fabs(r) < EPS)
            return 0;
        else
            return r > 0 ? 1 : -1;
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

struct Segment {
    Point p1, p2;
    double a, b, c;

    Segment(const Point &p1, const Point &p2) : p1(p1), p2(p2), a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    double distanceTo(const Point &p) const {
        if (Point(p1, p).dotProduct(Point(p1, p2)) >= -EPS && Point(p2, p).dotProduct(Point(p2, p1)) >= -EPS)
            return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
        else
            return min(p1.distanceTo(p), p2.distanceTo(p));
    }

    bool has(const Point &p) const {
        return distanceTo(p) < EPS;
    }

    int side(const Point &p) const {
        return Line(a, b, c).side(p);
    }

    double distanceTo(const Segment &that) const {
        Line l(a, b, c), thatL(that.a, that.b, that.c);
        if (l.intersectsWith(thatL)) {
            Point p = l.intersection(thatL);
            if (has(p) && that.has(p))
                return 0;
        }
        return min(min(distanceTo(that.p1), distanceTo(that.p2)), min(that.distanceTo(p1), that.distanceTo(p2)));
    }

    bool intersectsWith(const Segment &that) const {
        return distanceTo(that) < EPS;
    }

    Point intersection(const Segment &that) const {
        Line l(a, b, c), thatL(that.a, that.b, that.c);
        return l.intersection(thatL);
    }
};

struct Polygon {
    vector<Point> points;

    void addPoint(const Point &p) {
        points.push_back(p);
    }

    void cut(const Segment &s, const Point &o) {
        vector<Point> newPoints;
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()];
            Segment ab(a, b);

            newPoints.push_back(a);
            if (!ab.intersectsWith(s))
                continue;

            Point p = ab.intersection(s);
            if (p != a && p != b)
                newPoints.push_back(p);
        }

        int badSide = -s.side(o);

        vector<Point> resPoints;
        for (Point &p : newPoints)
            if (s.side(p) != badSide)
                resPoints.push_back(p);

        points = resPoints;
    }

    double area() const {
        double s = 0;
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()];
            s += a.crossProduct(b);
        }
        return fabs(s) / 2;
    }
};

bool solve(int test) {
    int n, w, h;
    Point o;
    if (!(cin >> n >> w >> h >> o.x >> o.y))
        return 0;

    Polygon polygon;
    polygon.addPoint(Point(0, 0));
    polygon.addPoint(Point(w, 0));
    polygon.addPoint(Point(w, h));
    polygon.addPoint(Point(0, h));

    for (int i = 0; i < n; i++) {
        Point a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        polygon.cut(Segment(a, b), o);
    }

    cout.precision(3);
    cout << "Case #" << test << ": " << fixed << polygon.area() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}