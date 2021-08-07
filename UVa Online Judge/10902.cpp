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
    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
};

struct Segment {
    Point p1, p2;

    bool intersectsWith(const Segment &that) const {
        double abx1 = min(p1.x, p2.x), abx2 = max(p1.x, p2.x);
        double cdx1 = min(that.p1.x, that.p2.x), cdx2 = max(that.p1.x, that.p2.x);
        if (max(abx1, cdx1) > min(abx2, cdx2))
            return 0;

        double aby1 = min(p1.y, p2.y), aby2 = max(p1.y, p2.y);
        double cdy1 = min(that.p1.y, that.p2.y), cdy2 = max(that.p1.y, that.p2.y);
        if (max(aby1, cdy1) > min(aby2, cdy2))
            return 0;

        Point ab(p1, p2), ac(p1, that.p1), ad(p1, that.p2);
        double abc = ab.crossProduct(ac), abd = ab.crossProduct(ad);
        if (abc > 0 && abd > 0 || abc < 0 && abd < 0)
            return 0;

        Point cd(that.p1, that.p2), ca(that.p1, p1), cb(that.p1, p2);
        double cda = cd.crossProduct(ca), cdb = cd.crossProduct(cb);
        if (cda > 0 && cdb > 0 || cda < 0 && cdb < 0)
            return 0;

        return 1;
    }
};

bool solve() {
    int segmentCount;
    cin >> segmentCount;

    if (!segmentCount)
        return 0;

    map<int, Segment> segments;
    for (int i = 0; i < segmentCount; i++) {
        Segment s;
        cin >> s.p1.x >> s.p1.y >> s.p2.x >> s.p2.y;

        for (auto it = segments.begin(); it != segments.end(); ) {
            if (s.intersectsWith(it->second))
                it = segments.erase(it);
            else
                it++;
        }

        segments.insert({ i, s });
    }

    cout << "Top sticks: ";
    for (auto it = segments.begin(); it != segments.end(); it++)
        cout << it->first + 1 << (next(it) != segments.end() ? ", " : ".\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}