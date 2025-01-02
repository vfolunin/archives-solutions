#include <iostream>
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

    void has(const Point &p) const {
        bool pos = 0, neg = 0, zero = 0;
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()];
            Point ab(a, b), ap(a, p);
            double cross = ab.crossProduct(ap);
            pos |= cross > EPS;
            neg |= cross < -EPS;
            zero |= abs(cross) < EPS;
        }
        
        if (pos && neg)
            cout << "OUTSIDE\n";
        else if (zero)
            cout << "ON BORDER\n";
        else
            cout << "INSIDE\n";
    }

    friend istream &operator >> (istream &in, Polygon &p) {
        int pointCount;
        in >> pointCount;

        p.points.resize(pointCount);
        for (Point &point : p.points)
            in >> point;

        return in;
    }
};

bool solve() {
    Polygon polygon;
    Point point;
    if (!(cin >> polygon >> point))
        return 0;

    polygon.has(point);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}