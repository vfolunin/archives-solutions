#include <iostream>
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
        return sqrt(x * x + y * y);
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

struct Line {
    double a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    Point intersection(const Line &that) const {
        double d = a * that.b - b * that.a;
        double dx = -c * that.b - b * -that.c;
        double dy = a * -that.c - -c * that.a;
        return Point(dx / d, dy / d);
    }
};

bool solve() {
    int circleCount;
    Point a;
    if (!(cin >> circleCount >> a.x >> a.y))
        return 0;

    vector<pair<double, double>> segments;

    for (int i = 0; i < circleCount; i++) {
        Point o;
        double r;
        cin >> o.x >> o.y >> r;

        double aoLen = a.distanceTo(o);
        double acLen = sqrt(aoLen * aoLen - r * r);
        double abLen = acLen * acLen / aoLen;
        double bcLen = acLen * r / aoLen;

        Point b = a + Point(a, o).setLength(abLen);
        Point c1 = b + Point(a, b).orthogonalPoint().setLength(bcLen);
        Point c2 = b - Point(a, b).orthogonalPoint().setLength(bcLen);

        Line l1(a, c1);
        Line l2(a, c2);
        Line l(Point(0, 0), Point(1, 0));

        double x1 = l1.intersection(l).x;
        double x2 = l2.intersection(l).x;

        if (x1 > x2)
            swap(x1, x2);

        segments.push_back({ x1, x2 });
    }

    sort(segments.begin(), segments.end());

    vector<pair<double, double>> resSegments;
    for (auto &[l, r] : segments) {
        if (resSegments.empty() || resSegments.back().second + EPS < l)
            resSegments.push_back({ l, r });
        else
            resSegments.back().second = max(resSegments.back().second, r);
    }

    cout.precision(2);
    for (auto &[l, r] : resSegments)
        cout << fixed << l << " " << r << "\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}