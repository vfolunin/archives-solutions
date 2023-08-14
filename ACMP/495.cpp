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

    Point midPointTo(Point &that) {
        return { (x + that.x) / 2, (y + that.y) / 2 };
    }

    double distanceTo(Point &that) {
        return hypot(x - that.x, y - that.y);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    int iterationCount;
    cin >> iterationCount;

    for (int i = 0; i < iterationCount; i++) {
        vector<Point> nextPoints;
        for (int j = 0; j < pointCount; j++)
            nextPoints.push_back(points[j].midPointTo(points[(j + 1) % points.size()]));
        points.swap(nextPoints);
    }

    double res = 0;
    for (int i = 0; i < pointCount; i++)
        res += points[i].distanceTo(points[(i + 1) % points.size()]);

    cout << fixed << res;
}