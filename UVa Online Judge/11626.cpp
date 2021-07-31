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

    bool operator < (const Point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }

    long long length2() const {
        return x * x + y * y;
    }

    long long crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
} o;

bool compareByAngle(const Point &a, const Point &b) {
    Point oa(o, a), ob(o, b);
    long long cross = oa.crossProduct(ob);
    if (cross)
        return cross > 0;
    if (o.y >= a.y)
        return oa.length2() < ob.length2();
    else
        return oa.length2() > ob.length2();
}

void solve() {
    int pointCount;
    cin >> pointCount;

    vector<Point> points;
    for (int i = 0; i < pointCount; i++) {
        Point point;
        char type;
        cin >> point.x >> point.y >> type;
        if (type == 'Y')
            points.push_back(point);
    }

    sort(points.begin(), points.end());
    o = points[0];
    sort(points.begin() + 1, points.end(), compareByAngle);

    cout << points.size() << "\n";
    for (auto &[x, y] : points)
        cout << x << " " << y << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}