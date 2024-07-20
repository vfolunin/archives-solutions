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

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Line {
    double a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x * p2.y - p2.x * p1.y) {}

    double distanceTo(const Point &p) const {
        return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double radius;
    Point o, a, b;
    cin >> radius >> o >> a >> b;

    double dist = Line(a, b).distanceTo(o);

    if (radius < dist - EPS)
        cout << -1;
    else if (abs(radius - dist) < EPS)
        cout << 0;
    else
        cout << fixed << sqrt(radius * radius - dist * dist) * 2;
}