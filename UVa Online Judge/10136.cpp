#include <iostream>
#include <sstream>
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

    double length() const {
        return hypot(x, y);
    }

    double distanceTo(const Point &that) const {
        return Point(*this, that).length();
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator - (const Point &that) const {
        return Point(x - that.x, y - that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    Point setLength(double newLength) const {
        double k = newLength / length();
        return Point(x * k, y * k);
    }

    Point orthogonalPoint() const {
        return Point(-y, x);
    }
};

const double R = 2.5;

int pointsInCircle(vector<Point> &points, const Point &center) {
    int res = 0;
    for (Point &point : points)
        res += center.distanceTo(point) <= R + EPS;
    return res;
}

void solve(int test) {
    vector<Point> points;

    while (1) {
        string line;
        getline(cin, line);

        if (line.empty())
            break;

        stringstream ss(line);
        Point point;
        ss >> point.x >> point.y;
        points.push_back(point);
    }

    int res = 0;

    for (Point &a : points) {
        res = max(res, pointsInCircle(points, a));

        for (Point &b : points) {
            double dist = a.distanceTo(b) / 2;
            if (dist > R + EPS)
                continue;

            Point c = (a + b) * 0.5;
            Point n = Point(a, b).orthogonalPoint().setLength(sqrt(R * R - dist * dist));

            res = max(res, pointsInCircle(points, c + n));
            res = max(res, pointsInCircle(points, c - n));
        }
    }

    if (test)
        cout << "\n";
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}