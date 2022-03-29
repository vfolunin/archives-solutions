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

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
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

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
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
};

bool solve() {
    int segmentCount;
    cin >> segmentCount;

    if (!segmentCount)
        return 0;

    vector<Segment> segments;
    for (int i = 0; i < segmentCount; i++) {
        Point a, b;
        cin >> a >> b;
        segments.push_back(Segment(a, b));
    }

    int triangleCount = 0;
    for (int a = 0; a < segmentCount; a++)
        for (int b = a + 1; b < segmentCount; b++)
            for (int c = b + 1; c < segmentCount; c++)
                triangleCount += segments[a].intersectsWith(segments[b]) &&
                                 segments[a].intersectsWith(segments[c]) &&
                                 segments[b].intersectsWith(segments[c]);

    cout << triangleCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}