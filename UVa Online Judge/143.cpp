#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double EPS = 1e-9;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator == (const Point &that) const {
        return fabs(x - that.x) < EPS && fabs(y - that.y) < EPS;
    }

    bool operator < (const Point &that) const {
        if (fabs(x - that.x) >= EPS)
            return x < that.x;
        return y < that.y;
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

struct Polygon {
    vector<Point> points;

    void normalize() {
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());
        if (points.size() == 3 && Point(points[0], points[1]).isCollinearTo(Point(points[0], points[2])))
            points.erase(points.begin() + 1);
    }

    double segmentContains(const Point &p) const {
        if (Point(points[0], p).dotProduct(Point(points[0], points[1])) >= -EPS &&
            Point(points[1], p).dotProduct(Point(points[1], points[0])) >= -EPS) {
            double a = points[0].y - points[1].y;
            double b = points[1].x - points[0].x;
            double c = points[0].x * points[1].y - points[1].x * points[0].y;
            return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b) < EPS;
        } else {
            return points[0] == p || points[1] == p;
        }
    }

    bool contains(const Point &p) const {
        if (points.size() == 1)
            return points[0] == p;

        if (points.size() == 2)
            return segmentContains(p);

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
};

bool solve() {
    Polygon triangle;
    triangle.points.resize(3);

    for (auto &[x, y] : triangle.points)
        cin >> x >> y;
    triangle.normalize();

    if (triangle.points.size() == 1 && triangle.points[0] == Point(0, 0))
        return 0;

    int res = 0;
    for (int x = 1; x < 100; x++)
        for (int y = 1; y < 100; y++)
            res += triangle.contains(Point(x, y));

    cout << setw(4) << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}