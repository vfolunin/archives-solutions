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

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator == (const Point &that) const {
        return abs(x - that.x) < EPS && abs(y - that.y) < EPS;
    }

    bool operator < (const Point &that) const {
        if (fabs(x - that.x) >= EPS)
            return x < that.x;
        return y + EPS < that.y;
    }

    double angle() const {
        double a = atan2(y, x);
        if (a < -EPS)
            a += 2 * acos(-1.0);
        return a;
    }

    double length() const {
        return hypot(x, y);
    }

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

vector<Point> convexHull(vector<Point> &points) {
    nth_element(points.begin(), points.begin(), points.end());
    sort(points.begin() + 1, points.end(), [&](Point &a, Point &b) {
        Point &o = points[0], oa(o, a), ob(o, b);
        return oa.crossProduct(ob) > 0 || oa.crossProduct(ob) == 0 && oa.length() < ob.length();
    });

    vector<Point> hull;
    for (Point &p : points) {
        while (hull.size() >= 2) {
            Point &a = hull[hull.size() - 2], &b = hull[hull.size() - 1];
            Point ab(a, b), ap(a, p);
            if (ab.crossProduct(ap) <= 0)
                hull.pop_back();
            else
                break;
        }
        hull.push_back(p);
    }

    return hull;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<Point> points;
    cin >> points.emplace_back();

    double angle = acos(-1) * 2 / pointCount;
    double deltaAngle = points[0].angle();
    double radius = points[0].length();

    for (int i = 1; i < pointCount; i++)
        points.push_back(Point(radius * cos(angle * i + deltaAngle), radius * sin(angle * i + deltaAngle)));

    Point a, b;
    cin >> a >> b;

    points.push_back(a);
    points.push_back(b);

    vector<Point> hull = convexHull(points);
    int found = 0;
    double perimeter = 0, perimeterPart = 0;

    for (int i = 0; i < hull.size(); i++) {
        if (hull[i] == a || hull[i] == b)
            found++;
        if (found == 1)
            perimeterPart += hull[i].distanceTo(hull[(i + 1) % hull.size()]);
        perimeter += hull[i].distanceTo(hull[(i + 1) % hull.size()]);
    }

    double res = a.distanceTo(b);
    if (found == 2)
        res = min(perimeterPart, perimeter - perimeterPart);

    cout.precision(2);
    cout << fixed << res;
}