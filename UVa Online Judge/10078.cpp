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

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    int crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
};

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    int sign = 0;
    for (int i = 0; i < pointCount; i++) {
        Point &a = points[i];
        Point &b = points[(i + 1) % pointCount];
        Point &c = points[(i + 2) % pointCount];
        
        Point ab(a, b);
        Point ac(a, c);
        int cross = ab.crossProduct(ac);

        if (cross > 0) {
            if (sign < 0) {
                cout << "Yes\n";
                return 1;
            }
            sign = 1;
        }
        if (cross < 0) {
            if (sign > 0) {
                cout << "Yes\n";
                return 1;
            }
            sign = -1;
        }
    }

    cout << "No\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}