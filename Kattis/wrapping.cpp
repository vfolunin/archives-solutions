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

    Point(double x = 0, double y = 0) : x(x), y(y) {}

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

    double area() {
        double s = 0;
        for (int i = 0; i < hull.size(); i++)
            s += hull[i].crossProduct(hull[(i + 1) % hull.size()]);
        return fabs(s) / 2;
    }
};

void solve() {
    int boardCount;
    cin >> boardCount;

    vector<Point> points;
    double boardArea = 0;

    for (int i = 0; i < boardCount; i++) {
        double cx, cy, w, h, phi;
        cin >> cx >> cy >> w >> h >> phi;
        phi *= acos(-1) / 180;

        double theta = atan2(h, w);
        double r = hypot(w / 2, h / 2);

        points.push_back({ cx - r * cos(phi + theta), cy + r * sin(phi + theta) });
        points.push_back({ cx + r * cos(phi + theta), cy - r * sin(phi + theta) });
        points.push_back({ cx - r * cos(phi - theta), cy + r * sin(phi - theta) });
        points.push_back({ cx + r * cos(phi - theta), cy - r * sin(phi - theta) });

        boardArea += h * w;
    }

    double hullArea = Hull(points).area();
    double res = boardArea / hullArea * 100;

    cout.precision(1);
    cout << fixed << res << " %\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}