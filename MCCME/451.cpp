#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
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
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    Polygon polygon;
    for (int i = 0; i < pointCount; i++) {
        Point p;
        cin >> p;
        polygon.addPoint(p);
    }

    Point p;
    cin >> p;

    cout << (polygon.has(p) ? "YES" : "NO");
}