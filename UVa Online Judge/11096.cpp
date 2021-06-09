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

void solve() {
    double length;
    int pointCount;
    cin >> length >> pointCount;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    cout.precision(5);
    cout << fixed << max(length, Hull(points).perimeter()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}