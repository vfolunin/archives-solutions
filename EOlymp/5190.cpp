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

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point rotate(double angle) {
        return Point(x * cos(angle) - y * sin(angle), y * cos(angle) + x * sin(angle));
    }

    friend ostream &operator << (ostream &out, const Point &p) {
        return out << p.x << " " << p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double abSize, acSize, angle;
    cin >> abSize >> acSize >> angle;

    Point a(0, 0);
    Point b(abSize, 0);
    Point c = a + Point(acSize, 0).rotate(angle / 180 * acos(-1));

    cout << fixed << a << "\n" << b << "\n" << c;
}