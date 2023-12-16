#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y, z;

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y, z - that.z);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y >> p.z;
    }
};

double triangleArea(Point &a, Point &b, Point &c) {
    double ab = a.distanceTo(b), ac = a.distanceTo(c), bc = b.distanceTo(c);
    double p = (ab + ac + bc) / 2;
    return sqrt(p * (p - ab) * (p - ac) * (p - bc));
}

double pyramidArea(Point &a, Point &b, Point &c, Point &d) {
    return triangleArea(a, b, c) + triangleArea(a, b, d) + triangleArea(a, c, d) + triangleArea(b, c, d);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point a, b, c, d;
    cin >> a >> b >> c >> d;

    cout.precision(1);
    cout << fixed << pyramidArea(a, b, c, d);
}