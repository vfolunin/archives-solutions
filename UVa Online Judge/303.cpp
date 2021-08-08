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

    Segment() {}

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

    bool intersectsWith(const Line &l) const {
        Line thisL(a, b, c);
        return thisL.intersectsWith(l) && has(thisL.intersection(l));
    }
};

bool solve() {
    int gateCount;
    cin >> gateCount;

    if (!gateCount)
        return 0;

    vector<Point> upperPoints(gateCount);
    vector<Point> lowerPoints(gateCount);
    vector<Segment> gates(gateCount);

    for (int i = 0; i < gateCount; i++) {
        cin >> upperPoints[i].x >> upperPoints[i].y;
        lowerPoints[i].x = upperPoints[i].x;
        lowerPoints[i].y = upperPoints[i].y - 1;
        gates[i] = Segment(upperPoints[i], lowerPoints[i]);
    }

    double resX = -1e9;

    for (Point &upperPoint : upperPoints) {
        for (Point &lowerPoint : lowerPoints) {
            if (fabs(upperPoint.x - lowerPoint.x) < EPS)
                continue;

            Line light(upperPoint, lowerPoint);

            int lastGate = 0;
            while (lastGate < gateCount && gates[lastGate].intersectsWith(light))
                lastGate++;

            if (!lastGate)
                continue;
             
            if (lastGate == gateCount) {
                cout << "Through all the pipe.\n";
                return 1;
            }

            Line upper(upperPoints[lastGate - 1], upperPoints[lastGate]);
            Line lower(lowerPoints[lastGate - 1], lowerPoints[lastGate]);
            resX = max(resX, light.intersection(upper).x);
            resX = max(resX, light.intersection(lower).x);
        }
    }

    cout.precision(2);
    cout << fixed << resX << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}