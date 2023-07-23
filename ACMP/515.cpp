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

    double length() const {
        return hypot(x, y);
    }

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

    int pointCount;
    cin >> pointCount;

    Point prevPoint = { 0, 0 };
    double res = 0;

    for (int i = 0; i < pointCount; i++) {
        Point point;
        cin >> point;

        res += prevPoint.distanceTo(point);
        prevPoint = point;
    }

    res += prevPoint.length();

    cout << fixed << res;
}