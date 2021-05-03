#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    long long x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    long long crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    long long area = 0, border = 0;
    for (int i = 0; i < pointCount; i++) {
        Point &a = points[i], &b = points[(i + 1) % pointCount], ab(a, b);
        area += a.crossProduct(b);
        border += gcd(abs(ab.x), abs(ab.y));
    }
    
    cout << (abs(area) + 2 - border) / 2 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}