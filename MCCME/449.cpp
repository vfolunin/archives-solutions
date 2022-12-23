#include <iostream>
#include <cmath>
#include <algorithm>
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
        double radius, angle;
        in >> radius >> angle;
        angle *= acos(-1) / 180;
        p.y = sin(angle) * radius;
        p.x = cos(angle) * radius;
        return in;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point a, b;
    cin >> a >> b;

    cout << fixed << a.distanceTo(b);
}