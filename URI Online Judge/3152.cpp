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

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
};

struct Polygon {
    vector<Point> points;

    void addPoint(const Point &p) {
        points.push_back(p);
    }

    double area() const {
        double s = 0;
        for (int i = 0; i < points.size(); i++)
            s += points[i].crossProduct(points[(i + 1) % points.size()]);
        return fabs(s) / 2;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Polygon a;
    for (int i = 0; i < 4; i++) {
        Point p;
        cin >> p.x >> p.y;
        a.addPoint(p);
    }

    Polygon b;
    for (int i = 0; i < 4; i++) {
        Point p;
        cin >> p.x >> p.y;
        b.addPoint(p);
    }

    if (a.area() > b.area() + 1e-9)
        cout << "terreno A\n";
    else
        cout << "terreno B\n";
}