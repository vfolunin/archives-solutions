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

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator <= (const Point &that) const {
        return y + EPS < that.y || abs(y - that.y) < EPS && x <= that.x + EPS;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Line {
    double a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    double distanceTo(const Point &p) const {
        return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }

    bool has(const Point &p) const {
        return distanceTo(p) < EPS;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  
    int pointCount;
    cin >> pointCount;

    vector<Point> points(pointCount);
    for (Point &point : points)
        cin >> point;

    long long res = pointCount * (pointCount - 1);
    for (Point &a : points) {
        for (Point &b : points) {
            if (b <= a)
                continue;

            Line line(a, b);

            int ok = 1, count = 0;
            for (Point &point : points) {
                if (line.has(point)) {
                    ok &= a <= point && point <= b;
                    count++;
                }
            }
            if (ok)
                res -= (count - 1) * (count - 2);
        }
    }

    cout << res;
}