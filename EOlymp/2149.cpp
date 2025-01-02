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

    bool isCollinearTo(const Point &that) const {
        return !crossProduct(that);
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
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()];
            Point ab(a, b), ap(a, p), bp(b, p);
            if (ap.isCollinearTo(ab) && ap.dotProduct(ab) >= 0 && bp.dotProduct(ab) <= 0)
                return 1;
        }

        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()];
            if (a.y == b.y || p.y < min(a.y, b.y) || p.y > max(a.y, b.y))
                continue;
            if (p.y == a.y && p.x < a.x || p.y == b.y && p.x < b.x)
                res ^= p.y == min(a.y, b.y);
            else
                res ^= p.x < a.x + (double)(p.y - a.y) / (b.y - a.y) * (b.x - a.x);
        }
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    Point point;
    cin >> pointCount >> point;

    Polygon polygon;
    for (int i = 0; i < pointCount; i++) {
        Point point;
        cin >> point;
        polygon.addPoint(point);
    }

    cout << (polygon.has(point) ? "YES" : "NO");
}