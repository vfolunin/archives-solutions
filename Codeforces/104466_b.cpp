#include <iostream>
#include <algorithm>
#include <cmath>
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

    bool isCollinearTo(const Point &that) const {
        return !crossProduct(that);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

bool canCover(vector<Point> &points, int lineCount) {
    if (points.size() <= lineCount)
        return 1;

    for (int a = 0; a <= lineCount; a++) {
        for (int b = a + 1; b <= lineCount; b++) {
            Point ab(points[a], points[b]);

            vector<Point> nextPoints;
            for (Point &point : points)
                if (!ab.isCollinearTo(Point(points[a], point)))
                    nextPoints.push_back(point);

            if (canCover(nextPoints, lineCount - 1))
                return 1;
        }
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<Point> points(pointCount);
    for (Point &point : points)
        cin >> point;

    cout << (canCover(points, 3) ? "possible" : "impossible");
}