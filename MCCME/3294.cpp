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

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator < (const Point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }


    int crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    bool isCollinearTo(const Point &that) const {
        return !crossProduct(that);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

void solve() {
    vector<Point> points(4);
    for (Point &point : points)
        cin >> point;

    sort(points.begin(), points.end());

    do {
        if (Point(points[0], points[1]).isCollinearTo(Point(points[2], points[3])) &&
            Point(points[0], points[2]).isCollinearTo(Point(points[1], points[3]))) {
            cout << "YES\n";
            return;
        }
    } while (next_permutation(points.begin(), points.end()));

    cout << "NO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}