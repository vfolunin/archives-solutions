#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    operator bool() {
        return x || y;
    }

    int crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

bool solve() {
    Point a, b, c;
    cin >> a >> b >> c;

    if (!a && !b && !c)
        return 0;

    Point ab(a, b), ac(a, c), bc(b, c);

    int area2 = abs(ab.crossProduct(ac));
    int outer = gcd(ab.x, ab.y) + gcd(ac.x, ac.y) + gcd(bc.x, bc.y);

    cout << (area2 - outer + 2) / 2 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}