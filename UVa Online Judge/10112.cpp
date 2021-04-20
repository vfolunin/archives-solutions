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

struct Triangle {
    Point a, b, c;

    long long area2() const {
        long long s = a.crossProduct(b);
        s += b.crossProduct(c);
        s += c.crossProduct(a);
        return abs(s);
    }

    bool contains(const Point &p) const {
        Point ab(a, b), bc(b, c), ca(c, a);
        Point ap(a, p), bp(b, p), cp(c, p);
        long long abp = ab.crossProduct(ap);
        long long bcp = bc.crossProduct(bp);
        long long cap = ca.crossProduct(cp);
        return abp >= 0 && bcp >= 0 && cap >= 0 || abp <= 0 && bcp <= 0 && cap <= 0;
    }
};

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<string> names(pointCount);
    vector<Point> points(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> names[i] >> points[i].x >> points[i].y;

    string bestNames;
    long long bestArea = 0;

    for (int ai = 0; ai < pointCount; ai++) {
        for (int bi = ai + 1; bi < pointCount; bi++) {
            for (int ci = bi + 1; ci < pointCount; ci++) {
                Triangle triangle = { points[ai], points[bi], points[ci] };
                
                bool ok = 1;
                for (int i = 0; ok && i < pointCount; i++)
                    ok &= i == ai || i == bi || i == ci || !triangle.contains(points[i]);
                if (!ok)
                    continue;

                long long curArea = triangle.area2();
                string curNames = "" + names[ai] + names[bi] + names[ci];
                sort(curNames.begin(), curNames.end());

                if (curArea > bestArea || curArea == bestArea && curNames < bestNames) {
                    bestArea = curArea;
                    bestNames = curNames;
                }
            }
        }
    }

    cout << bestNames << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}