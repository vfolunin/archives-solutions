#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double EPS = 1e-9;

struct Point {
    double x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }
};

int timeToCollision(Point &p1, Point &v1, Point &p2, Point &v2, double distance) {
    Point dp(p1, p2);
    Point dv(v1, v2);

    double dpdv = dp.dotProduct(dv);
    if (dpdv >= -EPS)
        return 1e9;

    double dpdp = dp.dotProduct(dp);
    double dvdv = dv.dotProduct(dv);

    double d = dpdv * dpdv - dvdv * (dpdp - distance * distance);
    if (d < -EPS)
        return 1e9;

    return round(-(dpdv + sqrt(d)) / dvdv);
}

void solve(int test) {
    int pointCount;
    double distance;
    cin >> pointCount >> distance;

    vector<Point> p(pointCount), v(pointCount);
    for (int i = 0; i < pointCount; i++) {
        double angle, dist;
        cin >> p[i].x >> p[i].y >> angle >> dist;
        angle = (90 - angle) * acos(-1) / 180;
        v[i].x = dist * cos(angle);
        v[i].y = dist * sin(angle);
    }

    int res = 1e9;

    for (int i = 0; i < pointCount; i++) {
        for (int j = i + 1; j < pointCount; j++) {
            if (p[i].distanceTo(p[j]) <= distance + EPS)
                res = 0;
            else
                res = min(res, timeToCollision(p[i], v[i], p[j], v[j], distance));
        }
    }

    if (res != 1e9)
        cout << res << "\n";
    else
        cout << "No collision.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}