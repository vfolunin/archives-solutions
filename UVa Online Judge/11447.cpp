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

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
};

struct Polygon {
    vector<Point> points;

    double area() {
        double s = 0;
        for (int i = 0; i < points.size(); i++)
            s += points[i].crossProduct(points[(i + 1) % points.size()]);
        return fabs(s) / 2;
    }
};

istream &operator >> (istream &in, Polygon &p) {
    int pointCount;
    in >> pointCount;

    p.points.resize(pointCount);
    for (auto &[x, y] : p.points)
        in >> x >> y;

    return in;
}

void solve() {
    Polygon polygon;
    double width, percent, spent, fell;
    cin >> polygon >> width >> percent >> spent >> fell;

    double volume = polygon.area() * width;
    double amount = volume * percent / 100;

    if (amount < spent - 1e-9)
        cout << "Lack of water. ";
    amount = max(0.0, amount - spent);

    if (amount + fell > volume + 1e-9)
        cout << "Excess of water. ";
    amount = min(volume, amount + fell);

    cout.precision(0);
    cout << "Final percentage: " << fixed << floor(amount / volume * 100) << "%\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}