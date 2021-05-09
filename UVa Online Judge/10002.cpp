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

    bool operator < (const Point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }

    long long length2() const {
        return x * x + y * y;
    }

    long long crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
} o;

bool compareByAngle(const Point &a, const Point &b) {
    Point oa(o, a), ob(o, b);
    return oa.crossProduct(ob) > 0 || (oa.crossProduct(ob) == 0 && oa.length2() < ob.length2());
}

struct Hull {
    vector<Point> hull;
    bool disabled = 0;

    Hull(vector<Point> &points) {
        sort(points.begin(), points.end());
        o = points[0];
        sort(points.begin() + 1, points.end(), compareByAngle);
        for (int i = 0; i < points.size(); i++) {
            while (hull.size() >= 2) {
                Point &o = hull[hull.size() - 2], &a = hull[hull.size() - 1], &b = points[i];
                Point oa(o, a), ob(o, b);
                if (oa.crossProduct(ob) <= 0)
                    hull.pop_back();
                else
                    break;
            }
            hull.push_back(points[i]);
        }
    }

    double area2() {
        double s = 0;
        for (int i = 0; i < hull.size(); i++)
            s += hull[i].crossProduct(hull[(i + 1) % hull.size()]);
        return abs(s);
    }

    double x() {
        double x = 0;
        for (int i = 0; i < hull.size(); i++)
            x += hull[i].crossProduct(hull[(i + 1) % hull.size()]) * (hull[i].x + hull[(i + 1) % hull.size()].x);
        return x / (3 * area2());
    }

    double y() {
        double y = 0;
        for (int i = 0; i < hull.size(); i++)
            y += hull[i].crossProduct(hull[(i + 1) % hull.size()]) * (hull[i].y + hull[(i + 1) % hull.size()].y);
        return y / (3 * area2());
    }
};

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (pointCount < 3)
        return 0;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    Hull hull(points);

    cout.precision(3);
    cout << fixed << hull.x() << " " << hull.y() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}