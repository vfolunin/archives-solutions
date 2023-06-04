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

    bool operator == (const Point &that) const {
        return abs(x - that.x) < EPS && abs(y - that.y) < EPS;
    }

    bool operator < (const Point &that) const {
        if (abs(x - that.x) >= EPS)
            return x < that.x;
        return y + EPS < that.y;
    }

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

    Point o1, o2;
    double radius1, radius2;
    cin >> o1 >> radius1 >> o2 >> radius2;

    double o1o2Dist = o1.distanceTo(o2);
    double radiusDiff = abs(radius1 - radius2);

    if (radius1 + radius2 + EPS < o1o2Dist || o1o2Dist + EPS < radiusDiff) {
        cout << 0;
    } else if (o1 == o2 && abs(radius1 - radius2) < EPS) {
        cout << 3;
    } else if (abs(o1o2Dist - radius1 - radius2) < EPS || abs(o1o2Dist - radiusDiff) < EPS) {
        cout << 1 << "\n" << fixed << (o1 + Point(o1, o2).setLength(radius1));
    } else {
        double o1hDist = (o1o2Dist * o1o2Dist + radius1 * radius1 - radius2 * radius2) / (2 * o1o2Dist);
        double hpDist = sqrt(radius1 * radius1 - o1hDist * o1hDist);

        Point h = o1 + Point(o1, o2).setLength(o1hDist);
        Point hp = Point(o1, o2).orthogonalPoint().setLength(hpDist);
        Point p1 = h + hp, p2 = h - hp;

        cout << 2 << "\n" << fixed << p1 << "\n" << p2;
    }
}