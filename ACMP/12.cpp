#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    long long x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    long long crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Polygon {
    vector<Point> points;

    Polygon(int pointCount) : points(pointCount) {}

    bool has(const Point &p) const {
        bool pos = 0, neg = 0;
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()];
            Point ab(a, b), ap(a, p);
            long long cross = ab.crossProduct(ap);
            pos |= cross > 0;
            neg |= cross < 0;
        }
        return !pos || !neg;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    int res = 0;
    for (int i = 0; i < queryCount; i++) {
        Point point;
        cin >> point;

        Polygon polygon(4);
        for (Point &point : polygon.points)
            cin >> point;

        res += polygon.has(point);
    }

    cout << res;
}