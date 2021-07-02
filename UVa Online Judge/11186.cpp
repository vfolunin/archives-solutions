#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
};

bool solve() {
    int pointCount, radius;
    cin >> pointCount >> radius;

    if (!pointCount && !radius)
        return 0;

    vector<Point> points;
    for (int i = 0; i < pointCount; i++) {
        double angle;
        cin >> angle;

        angle *= acos(-1) / 180;
        points.push_back(Point(radius * cos(angle), radius * sin(angle)));
    }

    double res = 0;
    for (int i = 0; i < pointCount; i++)
        for (int j = i + 1; j < pointCount; j++)
            for (int k = j + 1; k < pointCount; k++)
                res += fabs(Point(points[i], points[j]).crossProduct(Point(points[i], points[k])) / 2);

    cout.precision(0);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}