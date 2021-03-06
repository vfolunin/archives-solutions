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

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator < (const Point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }

    double length() const {
        return hypot(x, y);
    }

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
} o;

bool compareByAngle(const Point &a, const Point &b) {
    Point oa(o, a), ob(o, b);
    return oa.crossProduct(ob) < 0 || (oa.crossProduct(ob) == 0 && oa.length() < ob.length());
}

struct Hull {
    vector<Point> hull;

    Hull(vector<Point> &points) {
        sort(points.begin(), points.end());
        o = points[0];
        sort(points.begin() + 1, points.end(), compareByAngle);
        for (int i = 0; i < points.size(); i++) {
            while (hull.size() >= 2) {
                Point &o = hull[hull.size() - 2], &a = hull[hull.size() - 1], &b = points[i];
                Point oa(o, a), ob(o, b);
                if (oa.crossProduct(ob) >= 0)
                    hull.pop_back();
                else
                    break;
            }
            hull.push_back(points[i]);
        }
    }

    double perimeter() const {
        double p = 0;
        for (int i = 0; i < hull.size(); i++)
            p += Point(hull[i], hull[(i + 1) % hull.size()]).length();
        return p;
    }
};

bool solve(int test) {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    Hull hull(points);

    if (test > 1)
        cout << "\n";
    cout << "Region #" << test << ":\n";
    cout.precision(1);
    for (auto &[x, y] : hull.hull)
        cout << "(" << fixed << x << "," << y << ")-";
    cout << "(" << fixed << hull.hull[0].x << "," << hull.hull[0].y << ")\n";
    cout.precision(2);
    cout << "Perimeter length = " << fixed << hull.perimeter() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}