#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Segment {
    Point p1, p2;
    double a, b, c;

    Segment() {}

    Segment(const Point &p1, const Point &p2) : p1(p1), p2(p2), a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    double distanceTo(const Point &p) const {
        if (Point(p1, p).dotProduct(Point(p1, p2)) >= -EPS && Point(p2, p).dotProduct(Point(p2, p1)) >= -EPS)
            return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
        else
            return min(p1.distanceTo(p), p2.distanceTo(p));
    }

    friend istream &operator >> (istream &in, Segment &s) {
        Point p1, p2;
        in >> p1 >> p2;
        s = Segment(p1, p2);
        return in;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int distLimit, segmentCount, den;
    cin >> distLimit >> segmentCount >> den;

    int num = 0;
    for (int i = 0; i < segmentCount; i++) {
        Segment segment;
        cin >> segment;

        num += segment.distanceTo(Point(0, 0)) <= distLimit;
    }

    cout << num / den + 1;
}