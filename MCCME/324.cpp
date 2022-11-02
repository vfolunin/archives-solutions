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

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
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
    for (int i = 0; i < pointCount; i++)
        for (int j = i + 1; j < pointCount; j++)
            res = max(res, points[i].distanceTo(points[j]));

    cout.precision(15);
    cout << fixed << res;
}