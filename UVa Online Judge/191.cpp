#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    long long x, y;

    Point(long long x = 0, long long y = 0) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    long long crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

struct Segment {
    Point p1, p2;

    Segment(const Point &p1, const Point &p2) : p1(p1), p2(p2) {}

    bool intersectsWith(const Segment &that) const {
        long long abx1 = min(p1.x, p2.x), abx2 = max(p1.x, p2.x);
        long long cdx1 = min(that.p1.x, that.p2.x), cdx2 = max(that.p1.x, that.p2.x);
        if (max(abx1, cdx1) > min(abx2, cdx2))
            return 0;

        long long aby1 = min(p1.y, p2.y), aby2 = max(p1.y, p2.y);
        long long cdy1 = min(that.p1.y, that.p2.y), cdy2 = max(that.p1.y, that.p2.y);
        if (max(aby1, cdy1) > min(aby2, cdy2))
            return 0;

        Point ab(p1, p2), ac(p1, that.p1), ad(p1, that.p2);
        long long abc = ab.crossProduct(ac), abd = ab.crossProduct(ad);
        if (abc > 0 && abd > 0 || abc < 0 && abd < 0)
            return 0;

        Point cd(that.p1, that.p2), ca(that.p1, p1), cb(that.p1, p2);
        long long cda = cd.crossProduct(ca), cdb = cd.crossProduct(cb);
        if (cda > 0 && cdb > 0 || cda < 0 && cdb < 0)
            return 0;

        return 1;
    }
};

struct Rectangle {
    Point a, b, c, d;

    Rectangle(const Point &p1, const Point &p2) {
        a = { min(p1.x, p2.x), min(p1.y, p2.y) };
        c = { max(p1.x, p2.x), max(p1.y, p2.y) };
        b = { a.x, c.y };
        d = { c.x, a.y };
    }
    
    bool contains(const Point &p) const {
        return a.x <= p.x && p.x <= c.x && a.y <= p.y && p.y <= c.y;
    }

    bool intersectsWith(const Segment &s) const {
        return contains(s.p1) || contains(s.p2) ||
               Segment(a, b).intersectsWith(s) ||
               Segment(b, c).intersectsWith(s) ||
               Segment(c, d).intersectsWith(s) ||
               Segment(d, a).intersectsWith(s);
    }
};

void solve() {
    Point segmentP1, segmentP2, rectangleP1, rectangleP2;
    cin >> segmentP1 >> segmentP2 >> rectangleP1 >> rectangleP2;

    Rectangle rectangle(rectangleP1, rectangleP2);
    Segment segment(segmentP1, segmentP2);

    if (rectangle.intersectsWith(segment))
        cout << "T\n";
    else
        cout << "F\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}