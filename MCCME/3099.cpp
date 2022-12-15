#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-6;

struct Point {
    double x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator == (const Point &that) const {
        return fabs(x - that.x) < EPS && fabs(y - that.y) < EPS;
    }

    double length() const {
        return hypot(x, y);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    double angleTo(const Point &that) const {
        return acos(max(-1.0, min(1.0, dotProduct(that) / (length() * that.length()))));
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point a, o, b, p;
    cin >> a >> o >> b >> p;

    Point oa(o, a), ob(o, b), op(o, p);

    if (o == p || fabs(oa.angleTo(op) + op.angleTo(ob) - oa.angleTo(ob)) < EPS)
        cout << "YES";
    else
        cout << "NO";
}