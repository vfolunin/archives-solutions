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

    long long dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    long long crossProduct(const Point &that) const {
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

    bool hasOnSide(const Point &p) const {
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()];
            Point ab(a, b), ap(a, p), bp(b, p);
            if (!ab.crossProduct(ap) && ap.dotProduct(bp) <= 0)
                return 1;
        }
        return 0;
    }

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

    Polygon polygon;
    for (int i = 0; i < 3; i++) {
        Point p;
        cin >> p;
        polygon.addPoint(p);
    }

    Point p;
    cin >> p;

    if (polygon.hasOnSide(p))
        cout << "On";
    else if (polygon.has(p))
        cout << "In";
    else
        cout << "Out";
}