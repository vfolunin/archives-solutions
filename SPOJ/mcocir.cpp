#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-6;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double distance2To(const Point &that) const {
        double dx = x - that.x, dy = y - that.y;
        return dx * dx + dy * dy;
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    bool isCollinearTo(const Point &that) const {
        return abs(crossProduct(that)) < EPS;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Line {
    double a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    static Line LineByVector(const Point &p, const Point &v) {
        return Line(p, p + v);
    }

    Point normal() const {
        return Point(a, b);
    }

    Line orthogonalLine(const Point &p) const {
        return LineByVector(p, normal());
    }

    Point intersection(const Line &that) const {
        double d = a * that.b - b * that.a;
        double dx = -c * that.b - b * -that.c;
        double dy = a * -that.c - -c * that.a;
        return Point(dx / d, dy / d);
    }
};

Point circumcenter(Point &a, Point &b, Point &c) {
    Line l1 = Line(a, b).orthogonalLine((a + b) * 0.5);
    Line l2 = Line(a, c).orthogonalLine((a + c) * 0.5);
    return l1.intersection(l2);
}

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<Point> points(pointCount);
    for (Point &point : points)
        cin >> point;

    int res = min<int>(points.size(), 2);
    for (int ai = 0; ai < points.size(); ai++) {
        for (int bi = ai + 1; bi < points.size(); bi++) {
            for (int ci = bi + 1; ci < points.size(); ci++) {
                if (Point(points[ai], points[bi]).isCollinearTo(Point(points[ai], points[ci])))
                    continue;

                Point o = circumcenter(points[ai], points[bi], points[ci]);
                double radius2 = o.distance2To(points[ai]);

                int cur = 0;
                for (Point &p : points)
                    cur += abs(o.distance2To(p) - radius2) < EPS;
                res = max(res, cur);
            }
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}