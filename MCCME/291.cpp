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

    long long perimeterPoints() const {
        long long res = 0;
        for (int i = 0; i < points.size(); i++) {
            int dx = points[i].x - points[(i + 1) % points.size()].x;
            int dy = points[i].y - points[(i + 1) % points.size()].y;
            res += gcd(dx, dy);
        }
        return res;
    }

    long long area2() const {
        long long res = 0;
        for (int i = 0; i < points.size(); i++)
            res += points[i].crossProduct(points[(i + 1) % points.size()]);
        return abs(res);
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

    cout << (polygon.area2() + 2 - polygon.perimeterPoints()) / 2;
}