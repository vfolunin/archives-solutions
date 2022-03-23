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
        return y < that.y || y == that.y && x < that.x;
    }

    double length() const {
        return hypot(x, y);
    }

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }

    friend ostream &operator << (ostream &out, const Point &p) {
        return out << p.x << " " << p.y;
    }
};

Point o;
bool compareByAngle(const Point &a, const Point &b) {
    Point oa(o, a), ob(o, b);
    return oa.crossProduct(ob) > 0 || oa.crossProduct(ob) == 0 && oa.length() < ob.length();
}

vector<Point> convexHull(vector<Point> points) {
    sort(points.begin(), points.end());
    o = points[0];

    sort(points.begin() + 1, points.end(), compareByAngle);

    vector<Point> hull;
    for (int i = 0; i < points.size(); i++) {
        while (hull.size() >= 2) {
            Point &a = hull[hull.size() - 2], &b = hull[hull.size() - 1], &c = points[i];
            Point ab(a, b), ac(a, c);
            if (ab.crossProduct(ac) <= 0)
                hull.pop_back();
            else
                break;
        }
        hull.push_back(points[i]);
    }
    return hull;
}

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    set<Point> points;
    for (int i = 0; i < pointCount; i++) {
        Point point;
        cin >> point;
        points.insert(point);
    }

    vector<Point> hull = convexHull({ points.begin(), points.end() });
    
    cout << hull.size() << "\n";
    for (Point &point : hull)
        cout << point << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}