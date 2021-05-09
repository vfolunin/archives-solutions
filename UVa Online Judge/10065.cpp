#include <iostream>
#include <algorithm>
#include <cmath>
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
};

int area(const vector<Point> &points) {
    int s = 0;
    for (int i = 0; i < points.size(); i++)
        s += points[i].crossProduct(points[(i + 1) % points.size()]);
    return abs(s);
}

bool solve(int test) {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    double polygonArea = area(points);
    double hullArea = area(Hull(points).hull);
    double res = (hullArea - polygonArea) / hullArea * 100;

    cout << "Tile #" << test << "\n";
    cout.precision(2);
    cout << "Wasted Space = " << fixed << res << " %\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}