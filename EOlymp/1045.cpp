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
        return hypot(that.x - x, that.y - y);
    }

    friend istream &operator >> (istream &in, Point &p) {
        in >> p.x >> p.y;
        return in;
    }
};

bool solve() {
    Point a, b, c;
    if (!(cin >> a >> b >> c))
        return 0;

    double ab = a.distanceTo(b);
    double ac = a.distanceTo(c);
    double bc = b.distanceTo(c);
    double p = (ab + ac + bc) / 2;
    double s = sqrt(p * (p - ab) * (p - ac) * (p - bc));
    double r = ab * ac * bc / (4 * s);
    double l = 2 * acos(-1.0) * r;

    cout.precision(2);
    cout << fixed << l << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}