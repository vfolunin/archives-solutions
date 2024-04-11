#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    double length() const {
        return hypot(x, y);
    }

    int dotProduct(const Point &that) const {
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

    Point a, b;
    cin >> a >> b;

    cout << a.dotProduct(b) << "\n";
    cout << fixed << a.angleTo(b);
}