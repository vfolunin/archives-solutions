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

    bool operator < (const Point &that) const {
        if (fabs(x - that.x) >= EPS)
            return x < that.x;
        return y < that.y;
    }

    double length() const {
        return hypot(x, y);
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

    Point normal() const {
        return Point(a, b);
    }

    double distanceTo(const Point &p) const {
        return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }

    bool has(const Point &p) const {
        return distanceTo(p) < EPS;
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
        if (!l.normal().isCollinearTo(thatL.normal()))
            return l.intersection(thatL);
        if (!distanceTo(that.p1))
            return that.p1;
        return that.p2;
    }
};

struct Polygon {
    vector<Point> points;

    void addPoint(const Point &p) {
        points.push_back(p);
    }

    bool has(const Point &p) const {
        bool pos = 0, neg = 0;
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()];
            Point ab(a, b), ap(a, p);
            double cross = ab.crossProduct(ap);
            pos |= cross > EPS;
            neg |= cross < -EPS;
        }
        return !pos || !neg;
    }

    set<Point> intersection(const Polygon &that) const {
        set<Point> res;

        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()];
            Segment ab(a, b);

            for (int j = 0; j < that.points.size(); j++) {
                const Point &ta = that.points[j], &tb = that.points[(j + 1) % that.points.size()];
                Segment tab(ta, tb);

                if (ab.intersectsWith(tab))
                    res.insert(ab.intersection(tab));
            }
        }

        for (const Point &p : points)
            if (that.has(p))
                res.insert(p);

        for (const Point &p : that.points)
            if (has(p))
                res.insert(p);

        return res;
    }
};

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (pointCount < 3)
        return 0;

    Polygon a;
    for (int i = 0; i < pointCount; i++) {
        Point p;
        cin >> p.x >> p.y;
        a.addPoint(p);
    }

    cin >> pointCount;

    Polygon b;
    for (int i = 0; i < pointCount; i++) {
        Point p;
        cin >> p.x >> p.y;
        b.addPoint(p);
    }

    set<Point> intersection = a.intersection(b);
    
    cout << intersection.size() << "\n";
    cout.precision(2);
    for (auto &[x, y] : intersection)
        cout << fixed << x << " " << y << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}