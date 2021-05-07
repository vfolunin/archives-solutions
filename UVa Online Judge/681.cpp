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
        if (y != that.y)
            return y < that.y;
        return x < that.x;
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

void solve(int test) {
    int pointCount;
    cin >> pointCount;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    vector<Point> hull = Hull(points).hull;
    rotate(hull.begin(), min_element(hull.begin(), hull.end()), hull.end());

    if (test)
        cout << "-1\n";
    cout << hull.size() + 1 << "\n";
    for (auto &[x, y] : hull)
        cout << x << " " << y << "\n";
    cout << hull[0].x << " " << hull[0].y << "\n";

    int sep;
    cin >> sep;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << n << "\n";
    for (int i = 0; i < n; i++)
        solve(i);
}