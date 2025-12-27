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

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
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

struct Polygon {
    vector<Point> points;

    void addPoint(const Point &p) {
        points.push_back(p);
    }

    bool has(const Point &p) const {
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()];
            Point ab(a, b), ap(a, p), bp(b, p);
            if (ap.isCollinearTo(ab) && ap.dotProduct(ab) >= -EPS && bp.dotProduct(ab) <= EPS)
                return 1;
        }

        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()];
            if (abs(a.y - b.y) < EPS || p.y + EPS < min(a.y, b.y) || p.y - EPS > max(a.y, b.y))
                continue;
            if (abs(p.y - a.y) < EPS && p.x + EPS < a.x || abs(p.y - b.y) < EPS && p.x + EPS < b.x)
                res ^= abs(p.y - min(a.y, b.y)) < EPS;
            else
                res ^= p.x + EPS < a.x + (p.y - a.y) / (b.y - a.y) * (b.x - a.x);
        }
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    Polygon polygon;
    for (int i = 0; i < pointCount; i++) {
        Point point;
        cin >> point;
        polygon.addPoint(point);
    }

    Point point;
    cin >> point;

    cout << (polygon.has(point) ? "YES" : "NO");
}