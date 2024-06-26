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

    double length() const {
        return hypot(x, y);
    }

    Point setLength(double newLength) const {
        double k = newLength / length();
        return Point(x * k, y * k);
    }

    Point rotate(double angle) {
        return Point(x * cos(angle) - y * sin(angle), y * cos(angle) + x * sin(angle));
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }

    friend ostream &operator << (ostream &out, const Point &p) {
        return out << p.x << " " << p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point a, b;
    int length;
    cin >> a >> b >> length;

    Point ab(a, b);

    cout << fixed << ab << "\n";
    cout << ab.setLength(1) << "\n";
    cout << ab.setLength(length) << "\n";
    cout << fixed << ab.rotate(asin(-1)) << "\n";
    cout << fixed << ab.rotate(asin(1)) << "\n";
}