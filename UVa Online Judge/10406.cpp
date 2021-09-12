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
        return hypot(x, y);
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    Point setLength(double newLength) const {
        double k = newLength / length();
        return Point(x * k, y * k);
    }

    Point orthogonalPoint() const {
        return Point(-y, x);
    }

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
};

struct Line {
    double a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    static Line LineByVector(const Point &p, const Point &v) {
        return Line(p, p + v);
    }

    static Line LineByNormal(const Point &p, const Point &n) {
        return LineByVector(p, n.orthogonalPoint());
    }

    Point normal() const {
        return Point(a, b);
    }

    Line parallelLine(double distance) const {
        Point p = (fabs(a) < EPS ? Point(0, -c / b) : Point(-c / a, 0));
        Point p1 = p + normal().setLength(distance);
        return LineByNormal(p1, normal());
    }

    Point intersection(const Line &that) const {
        double d = a * that.b - b * that.a;
        double dx = -c * that.b - b * -that.c;
        double dy = a * -that.c - -c * that.a;
        return Point(dx / d, dy / d);
    }
};

struct Polygon {
    vector<Point> points;

    void addPoint(const Point &p) {
        points.push_back(p);
    }

    double area() const {
        double s = 0;
        for (int i = 0; i < points.size(); i++)
            s += points[i].crossProduct(points[(i + 1) % points.size()]);
        return fabs(s) / 2;
    }
};

bool solve() {
    double width;
    int pointCount;
    cin >> width >> pointCount;

    if (!pointCount)
        return 0;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    vector<Line> lines;
    for (int i = 0; i < pointCount; i++) {
        Point &a = points[i], &b = points[(i + 1) % pointCount];
        lines.push_back(Line(a, b).parallelLine(-width));
    }

    Polygon polygon;
    for (int i = 0; i < pointCount; i++) {
        Line &a = lines[i], &b = lines[(i + 1) % pointCount];
        polygon.addPoint(a.intersection(b));
    }

    cout.precision(3);
    cout << fixed << polygon.area() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}