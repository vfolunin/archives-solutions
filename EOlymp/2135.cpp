#include <iostream>
#include <cmath>
#include <algorithm>
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

    int side(const Point &p) const {
        double r = a * p.x + b * p.y + c;
        if (fabs(r) < EPS)
            return 0;
        else
            return r > 0 ? 1 : -1;
    }

    friend istream &operator >> (istream &in, Line &l) {
        return in >> l.a >> l.b >> l.c;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point a, b;
    Line l;
    cin >> a >> b >> l;

    if (l.side(a) == l.side(b))
        cout << "YES";
    else
        cout << "NO";
}