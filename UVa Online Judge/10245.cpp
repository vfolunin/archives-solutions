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

    bool operator < (const Point &that) const {
        return x < that.x || x == that.x && y < that.y;
    }

    double distTo(const Point &that) {
        return hypot(x - that.x, y - that.y);
    }
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

double minDist(vector<Point> &points, int l, int r) {
    if (l >= r)
        return 1e9;

    int m = l + (r - l) / 2;
    double mx = (points[m].x + points[m + 1].x) / 2;
    double minDistL = minDist(points, l, m);
    double minDistR = minDist(points, m + 1, r);
    double minDist = min(minDistL, minDistR);

    for (int i = m; i >= l && mx - points[i].x < minDist; i--)
        for (int j = m + 1; j <= r && points[j].x - mx < minDist; j++)
            minDist = min(minDist, points[i].distTo(points[j]));

    return minDist;
}

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<Point> points(pointCount);
    for (Point &p : points)
        cin >> p;

    sort(points.begin(), points.end());
    double dist = minDist(points, 0, pointCount - 1);

    if (dist >= 1e4) {
        cout << "INFINITY\n";
    } else {
        cout.precision(4);
        cout << fixed << dist << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}