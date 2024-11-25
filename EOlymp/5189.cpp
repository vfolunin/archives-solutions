#include <iostream>
#include <algorithm>
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

    Point operator - (const Point &that) const {
        return Point(x - that.x, y - that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    Point orthogonalPoint() const {
        return Point(-y, x);
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

    Point a, c;
    cin >> a >> c;

    Point o = a + Point(a, c) * 0.5;
    Point b = o + Point(a, c).orthogonalPoint() * 0.5;
    Point d = o - Point(a, c).orthogonalPoint() * 0.5;

    cout << fixed << a << "\n" << b << "\n" << c << "\n" << d;
}