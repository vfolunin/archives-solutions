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

    long long crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
};

struct Segment {
    Point p1, p2;

    Segment() {}

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

void solve(int test) {
    int segmentCount;
    cin >> segmentCount;

    vector<Segment> segments(segmentCount);
    for (auto &[p1, p2] : segments)
        cin >> p1.x >> p1.y >> p2.x >> p2.y;

    int res = segmentCount;
    for (int i = 0; i < segmentCount; i++)
        for (int j = i + 1; j < segmentCount; j++)
            if (segments[i].intersectsWith(segments[j]))
                res += 2;

    if (test)
        cout << "\n";
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}