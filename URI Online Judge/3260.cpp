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
        return y < that.y || y == that.y && x < that.x;
    }

    long long length2() const {
        return x * x + y * y;
    }

    long long dist2To(const Point &that) const {
        return (x - that.x) * (x - that.x) + (y - that.y) * (y - that.y);
    }

    long long crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        in >> p.x >> p.y;
        return in;
    }
};

vector<Point> convexHull(vector<Point> &points) {
    nth_element(points.begin(), points.begin(), points.end());
    sort(points.begin() + 1, points.end(), [&](Point &a, Point &b) {
        Point &o = points[0], oa(o, a), ob(o, b);
        return oa.crossProduct(ob) > 0 || oa.crossProduct(ob) == 0 && oa.length2() < ob.length2();
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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int pointCount;
    cin >> pointCount;

    vector<Point> points(pointCount);
    for (Point &point : points)
        cin >> point;

    long long res = 0;

    vector<Point> hull = convexHull(points);
    hull.insert(hull.end(), hull.begin(), hull.end());

    for (int l = 0, r = 0; l < hull.size(); l++) {
        while (r + 1 < hull.size() && hull[l].dist2To(hull[r]) <= hull[l].dist2To(hull[r + 1])) {
            res = max(res, hull[l].dist2To(hull[r]));
            r++;
        }
        res = max(res, hull[l].dist2To(hull[r]));
    }

    cout.precision(8);
    cout << fixed << sqrt(res) << "\n";
}