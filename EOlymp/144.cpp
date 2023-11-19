#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    long long x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    long long dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    bool isOrthogonalTo(const Point &that) const {
        return !dotProduct(that);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Point> points(4);
    for (Point &point : points)
        cin >> point;

    int res = 0;
    for (int i = 0; i < points.size(); i++) {
        Point &a = points[i];
        Point &b = points[(i + 1) % points.size()];
        Point &c = points[(i + 2) % points.size()];
        res += Point(b, a).isOrthogonalTo(Point(b, c));
    }

    cout << res;
}