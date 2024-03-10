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
};

struct Line {
    int a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    int side(const Point &p) const {
        int r = a * p.x + b * p.y + c;
        if (!r)
            return 0;
        else
            return r > 0 ? 1 : -1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, y1, y2;
    cin >> n >> y1 >> y2;

    Line line(Point(0, y1), Point(100 * n, y2));
    int res = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            Point a(100 * x, 100 * y);
            Point b(100 * x, 100 * y + 100);
            Point c(100 * x + 100, 100 * y);
            Point d(100 * x + 100, 100 * y + 100);

            res += line.side(a) * line.side(b) <= 0 ||
                   line.side(a) * line.side(c) <= 0 ||
                   line.side(b) * line.side(d) <= 0 ||
                   line.side(c) * line.side(d) <= 0;
        }
    }

    cout << res;
}