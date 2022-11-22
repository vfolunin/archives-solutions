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

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<Point> points(pointCount);
    for (Point &point : points)
        cin >> point;

    double res = 0;
    for (int a = 0; a < points.size(); a++)
        for (int b = a + 1; b < points.size(); b++)
            for (int c = b + 1; c < points.size(); c++)
                res = max(res, abs(Point(points[a], points[b]).crossProduct(Point(points[a], points[c]))) / 2);

    cout.precision(15);
    cout << fixed << res;
}