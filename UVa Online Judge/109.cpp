#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator < (const Point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }

    double length2() const {
        return x * x + y * y;
    }

    double crossProduct(const Point &that) const {
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

    bool contains(const Point &p) const {
        bool pos = 0, neg = 0;
        for (int i = 0; i < hull.size(); i++) {
            const Point &a = hull[i], &b = hull[(i + 1) % hull.size()];
            Point ab(a, b), ap(a, p);
            int cross = ab.crossProduct(ap);
            pos |= cross > 0;
            neg |= cross < 0;
        }
        return !pos || !neg;
    }

    int area2() const {
        int s = 0;
        for (int i = 0; i < hull.size(); i++)
            s += hull[i].crossProduct(hull[(i + 1) % hull.size()]);
        return abs(s);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Hull> hulls;
    while (1) {
        int pointCount;
        cin >> pointCount;

        if (pointCount == -1)
            break;

        vector<Point> points(pointCount);
        for (auto &[x, y] : points)
            cin >> x >> y;

        hulls.push_back(Hull(points));
    }

    Point p;
    while (cin >> p.x >> p.y) {
        for (Hull &hull : hulls)
            if (!hull.disabled && hull.contains(p))
                hull.disabled = 1;
    }

    int res = 0;
    for (Hull &hull : hulls)
        if (hull.disabled)
            res += hull.area2();

    cout << res / 2 << (res % 2 ? ".50\n" : ".00\n");
}