#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }

    friend ostream &operator << (ostream &out, const Point &p) {
        return out << p.x << " " << p.y;
    }
};

double getDist(const Point &o, vector<Point> &points) {
    double dist = 0;
    for (Point &point : points)
        dist += o.distanceTo(point);
    return dist;
}

pair<double, double> getY(double x, vector<Point> &points) {
    double l = -1e9, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        double dist1 = getDist(Point(x, m1), points);
        double dist2 = getDist(Point(x, m2), points);

        if (dist1 < dist2)
            r = m2;
        else
            l = m1;
    }
    return { l, getDist(Point(x, l), points) };
}

Point getXY(vector<Point> &points) {
    double l = -1e9, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        auto [y1, dist1] = getY(m1, points);
        auto [y2, dist2] = getY(m2, points);

        if (dist1 < dist2)
            r = m2;
        else
            l = m1;
    }
    return Point(l, getY(l, points).first);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    vector<Point> points(4);
    for (Point &point : points)
        cin >> point;

    cout << fixed << getXY(points);
}