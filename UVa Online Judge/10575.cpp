#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    int distance2To(const Point &that) {
        int dx = x - that.x;
        int dy = y - that.y;
        return dx * dx + dy * dy;
    }
};

bool testPoint(vector<Point> &points, int i) {
    int n = points.size();
    for (int d = 0; d < n; d++) {
        int l1 = (i - d + n) % n;
        int r1 = (i + d) % n;
        if (points[i].distance2To(points[l1]) != points[i].distance2To(points[r1]))
            return 0;
        int l2 = (l1 - 1 + n) % n;
        int r2 = (r1 + 1) % n;
        if (points[i].distance2To(points[l2]) != points[i].distance2To(points[r2]))
            return 0;
        if (points[l1].distance2To(points[l2]) != points[r1].distance2To(points[r2]))
            return 0;
    }
    return 1;
}

bool testSide(vector<Point> &points, int i) {
    int n = points.size(), j = (i + 1) % n;
    for (int d = 0; d < n; d++) {
        int l = (i - d + n) % n;
        int r = (j + d) % n;
        if (points[i].distance2To(points[l]) != points[j].distance2To(points[r]))
            return 0;
        if (points[j].distance2To(points[l]) != points[i].distance2To(points[r]))
            return 0;
    }
    return 1;
}

bool solve(int test) {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    int res = 0;
    for (int i = 0; i < pointCount; i++) {
        res += testPoint(points, i);
        res += testSide(points, i);
    }

    cout << "Polygon #" << test << " has " << res / 2 << " symmetry line(s).\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}