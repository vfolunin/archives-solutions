#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(int x, int y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator < (const Point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    long long dotProduct(const Point &that) const {
        return 1LL * x * that.x + 1LL * y * that.y;
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

    int pointCount;
    cin >> pointCount;

    vector<Point> points(pointCount);
    for (Point &point : points)
        cin >> point;

    sort(points.begin(), points.end());

    int res = 0;
    for (int ai = 0; ai < points.size(); ai++) {
        for (int bi = 0; bi < points.size(); bi++) {
            if (ai == bi)
                continue;

            Point ab(points[ai], points[bi]);

            for (int ci = 0; ci < points.size(); ci++) {
                if (ai == ci || bi == ci)
                    continue;

                Point ac(points[ai], points[ci]);
                if (!ab.isOrthogonalTo(ac))
                    continue;

                res += binary_search(points.begin(), points.end(), points[ai] + ab + ac);
            }
        }
    }

    cout << res / 8;
}