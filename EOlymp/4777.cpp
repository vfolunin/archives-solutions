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

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    Point orthogonalPoint() const {
        return Point(-y, x);
    }

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
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

    Point a, b, c, d;
    cin >> a >> b >> c >> d;

    Point ab(a, b), cd(c, d);

    cout.precision(9);
    cout << fixed << ab.length() << " " << cd.length() << "\n";
    cout << ab + cd << "\n";
    cout << ab.dotProduct(cd) << " " << ab.crossProduct(cd) << "\n";
    cout << abs(ab.crossProduct(cd)) / 2 << "\n";
}