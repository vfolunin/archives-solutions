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

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

bool can(Point &start, Point &finish, Point &wind1, Point &wind2, double speed, double windChangeTime, double time) {
    Point location = start + wind1 * min(time, windChangeTime);
    location = location + wind2 * max(time - windChangeTime, 0.);
    return location.distanceTo(finish) / speed <= time;
}

int main() {
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);

    Point start, finish, wind1, wind2;
    double speed, windChangeTime;
    cin >> start >> finish >> speed >> windChangeTime >> wind1 >> wind2;

    double l = 0, r = 1;
    while (!can(start, finish, wind1, wind2, speed, windChangeTime, r))
        r *= 2;

    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (can(start, finish, wind1, wind2, speed, windChangeTime, m))
            r = m;
        else
            l = m;
    }

    cout << fixed << r;
}