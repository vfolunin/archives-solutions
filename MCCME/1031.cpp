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

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double length() const {
        return hypot(x, y);
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    Point setLength(double newLength) const {
        double k = newLength / length();
        return Point(x * k, y * k);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }

    friend ostream &operator << (ostream &out, const Point &p) {
        return out << fixed << p.x << " " << p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    double w, h;
    cin >> w >> h;

    Point a, b, c, d;
    cin >> a >> b >> c >> d;

    Point vx(a, b), vy(a, d);
    double scaleX = vx.length() / w;
    double scaleY = vy.length() / h;
    vx = vx.setLength(1);
    vy = vy.setLength(1);

    Point p(w / 2, h / 2);
    for (int i = 0; i < 100; i++)
        p = a + vx * (scaleX * p.x) + vy * (scaleY * p.y);

    cout.precision(3);
    cout << p;
}