#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double length() const {
        return hypot(x, y);
    }

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator - (const Point &that) const {
        return Point(x - that.x, y - that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    Point setLength(double newLength) const {
        double k = newLength / length();
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

    Point o, p;
    double radius;
    cin >> o >> radius >> p;

    double opDist = o.distanceTo(p);
    if (opDist + EPS < radius) {
        cout << 0;
    } else if (opDist <= radius + EPS) {
        cout << "1\n" << fixed << p;
    } else {
        double apDist = sqrt(opDist * opDist - radius * radius);
        double cpDist = apDist * apDist / opDist;
        double acDist = apDist * radius / opDist;
        Point c = p + Point(p, o).setLength(cpDist);
        Point ca = Point(p, o).orthogonalPoint().setLength(acDist);

        cout << "2\n";
        cout << fixed << c + ca << "\n";
        cout << fixed << c - ca << "\n";
    }
}