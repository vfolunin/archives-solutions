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

    int getBadPoint() {
        int pos = 0, neg = 0;
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()], &c = points[(i + 2) % points.size()];
            Point ab(a, b), ac(a, c);
            pos += ab.crossProduct(ac) > EPS;
            neg += ab.crossProduct(ac) < -EPS;
        }

        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()], &c = points[(i + 2) % points.size()];
            Point ab(a, b), ac(a, c);
            if (pos == 1 && ab.crossProduct(ac) > EPS || neg == 1 && ab.crossProduct(ac) < -EPS)
                return (i + 1) % points.size();
        }

        return -1;
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Polygon polygon;
    cin >> polygon;

    cout << polygon.getBadPoint() + 1;
}