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

    Point(double x, double y) : x(x), y(y) {}
};

struct Line {
    double a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    Point intersection(const Line &that) const {
        double d = a * that.b - b * that.a;
        double dx = -c * that.b - b * -that.c;
        double dy = a * -that.c - -c * that.a;
        return Point(dx / d, dy / d);
    }
};

bool solve() {
    double s, v1, v2, dt1, dt2, maxT;
    if (!(cin >> s >> v1 >> v2 >> dt1 >> dt2 >> maxT))
        return 0;

    int res = 0;
    for (int t1 = 0; t1 <= maxT; t1 += dt1) {
        Line l1(Point(0, t1), Point(s, t1 + s / v1));
        for (int t2 = 0; t2 <= maxT; t2 += dt2) {
            Line l2(Point(s, t2), Point(0, t2 + s / v2));
            Point p = l1.intersection(l2);
            res += -EPS <= p.x && p.x <= s + EPS && p.y <= maxT + EPS;
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}