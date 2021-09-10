#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }
};

void solve() {
    Point p, q, r;
    cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y;

    double m1, m2, m3, m4, m5, m6;
    cin >> m1 >> m2 >> m3 >> m4 >> m5 >> m6;

    double ka = m5 / m6;
    double kb = m1 / m2;
    double kc = m3 / m4;
    double kd = 1 - ka * kb * kc;
    
    Point a = r + Point(p, r) * ((ka + ka * kb * (1 + kc)) / kd);
    Point b = p + Point(q, p) * ((kb + kb * kc * (1 + ka)) / kd);
    Point c = q + Point(r, q) * ((kc + kc * ka * (1 + kb)) / kd);

    cout.precision(8);
    cout << fixed << a.x << " " << a.y << " ";
    cout << fixed << b.x << " " << b.y << " ";
    cout << fixed << c.x << " " << c.y << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}