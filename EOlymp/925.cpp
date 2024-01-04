#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Polygon {
    vector<Point> points;

    Polygon(int pointCount) : points(pointCount) {}

    double perimeter() const {
        double p = 0;
        for (int i = 0; i < points.size(); i++)
            p += points[i].distanceTo(points[(i + 1) % points.size()]);
        return p;
    }

    double area() const {
        double s = 0;
        for (int i = 0; i < points.size(); i++)
            s += points[i].crossProduct(points[(i + 1) % points.size()]);
        return abs(s) / 2;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Polygon polygon(3);
    for (Point &point : polygon.points)
        cin >> point;

    cout << fixed << polygon.perimeter() << " " << polygon.area();
}