#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

struct Point {
    long long x, y;

    long long crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Polygon {
    vector<Point> points;

    long long area2() const {
        long long res = 0;
        for (int i = 0; i < points.size(); i++)
            res += points[i].crossProduct(points[(i + 1) % points.size()]);
        return abs(res);
    }

    long long borderCount() const {
        long long res = 0;
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()];
            res += gcd(abs(a.x - b.x), abs(a.y - b.y));
        }
        return res;
    }

    friend istream &operator >> (istream &in, Polygon &polygon) {
        int pointCount;
        in >> pointCount;

        polygon.points.resize(pointCount);
        for (Point &point : polygon.points)
            in >> point;

        return in;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Polygon polygon;
    cin >> polygon;

    long long borderCount = polygon.borderCount();
    long long innerCount = (polygon.area2() + 2 - borderCount) / 2;

    cout << innerCount;
}