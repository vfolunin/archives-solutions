#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    double crossProduct(Point &that) {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Polygon {
    vector<Point> points;

    Polygon(int pointCount) : points(pointCount) {}

    double area() {
        double s = points[points.size() - 1].crossProduct(points[0]);
        for (int i = 0; i + 1 < points.size(); i++)
            s += points[i].crossProduct(points[i + 1]);
        return abs(s) / 2;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int pointCount;
    cin >> pointCount;

    Polygon polygon(pointCount);
    for (Point &point : polygon.points)
        cin >> point;

    cout.precision(1);
    cout << fixed << polygon.area();
}