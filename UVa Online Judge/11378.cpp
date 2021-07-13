#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    bool operator < (const Point &that) const {
        return x < that.x || x == that.x && y < that.y;
    }

    int distTo(const Point &that) {
        return max(abs(x - that.x), abs(y - that.y));
    }
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

int minDist(vector<Point> &points, int l, int r) {
    if (l >= r)
        return 1e9;

    int m = l + (r - l) / 2;
    int mx = (points[m].x + points[m + 1].x + 1) / 2;
    int minDistL = minDist(points, l, m);
    int minDistR = minDist(points, m + 1, r);
    int minDist = min(minDistL, minDistR);

    for (int i = m; i >= l && mx - points[i].x < minDist; i--)
        for (int j = m + 1; j <= r && points[j].x - mx < minDist; j++)
            minDist = min(minDist, points[i].distTo(points[j]));

    return minDist;
}

bool solve() {
    int pointCount;
    if (!(cin >> pointCount))
        return 0;

    vector<Point> points(pointCount);
    for (Point &p : points)
        cin >> p;

    sort(points.begin(), points.end());
    int res = minDist(points, 0, pointCount - 1);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}