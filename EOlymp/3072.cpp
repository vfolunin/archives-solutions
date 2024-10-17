#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double PI = acos(-1), EPS = 1e-6;

struct Point {
    double x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double length() const {
        return hypot(x, y);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    double angleTo(const Point &that) const {
        return acos(max(-1.0, min(1.0, dotProduct(that) / (length() * that.length()))));
    }
};

bool isInteger(double x) {
    return fabs(x - round(x)) < EPS;
}

bool solve() {
    string s;
    cin >> s;

    if (s == "END")
        return 0;

    Point a, b, c;
    a.x = stod(s);
    cin >> a.y >> b.x >> b.y >> c.x >> c.y;

    double alpha = Point(a, b).angleTo(Point(a, c)) / PI;
    double beta = Point(b, c).angleTo(Point(b, a)) / PI;

    int res = 3;
    while (!isInteger(alpha * res) || !isInteger(beta * res))
        res++;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}