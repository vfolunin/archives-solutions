#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
};

istream &operator >> (istream &in, Point &p) {
    return in >> p.x >> p.y;
}

struct Polygon {
    vector<Point> points;

    void addPoint(const Point &p) {
        points.push_back(p);
    }

    double signedArea() const {
        double s = 0;
        for (int i = 0; i < points.size(); i++)
            s += points[i].crossProduct(points[(i + 1) % points.size()]);
        return s / 2;
    }
};

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    Polygon polygon;
    for (int i = 0; i < pointCount; i++) {
        Point point;
        cin >> point;
        polygon.addPoint(point);
    }

    double signedArea = polygon.signedArea();

    cout << (signedArea >= 0 ? "CCW " : "CW ");
    cout.precision(1);
    cout << fixed << abs(signedArea) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}