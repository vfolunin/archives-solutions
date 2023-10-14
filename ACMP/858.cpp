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
};

struct Line {
    double a, b, c;

    Point intersection(const Line &that) const {
        double d = a * that.b - b * that.a;
        double dx = -c * that.b - b * -that.c;
        double dy = a * -that.c - -c * that.a;
        return Point(dx / d, dy / d);
    }

    friend istream &operator >> (istream &in, Line &l) {
        return in >> l.a >> l.b >> l.c;
    }
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    Line abl, acl, bcl;
    cin >> abl >> acl >> bcl;

    Point a = abl.intersection(acl);
    Point b = abl.intersection(bcl);
    Point c = acl.intersection(bcl);

    double ab = a.distanceTo(b);
    double ac = a.distanceTo(c);
    double bc = b.distanceTo(c);
    double p = (ab + ac + bc) / 2;

    cout << fixed << sqrt(p * (p - ab) * (p - ac) * (p - bc));
}