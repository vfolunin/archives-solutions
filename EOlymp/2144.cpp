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

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Line {
    double a, b, c;

    double distanceTo(const Point &p) const {
        return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }

    friend istream &operator >> (istream &in, Line &l) {
        return in >> l.a >> l.b >> l.c;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point p;
    Line l;
    cin >> p >> l;

    cout << fixed << l.distanceTo(p);
}