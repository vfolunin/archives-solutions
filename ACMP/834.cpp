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

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point p, o;
    double radius;
    cin >> p >> o >> radius;

    double op = o.distanceTo(p);
    if (op <= radius) {
        cout << fixed << acos(-1) * radius * radius;
        return 0;
    }

    double tangent = sqrt(op * op - radius * radius);
    double angle = acos(-1) - acos(radius / op);
    cout << fixed << tangent * radius + angle * radius * radius;
}