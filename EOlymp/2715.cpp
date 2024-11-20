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

    Point(long long x, long long y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator == (const Point &that) const {
        return x == that.x && y == that.y;
    }

    bool operator < (const Point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }

    long long length2() const {
        return x * x + y * y;
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    long long dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
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

    vector<Point> points(4);
    for (Point &point : points)
        cin >> point;

    sort(points.begin(), points.end());

    do {
        Point &a = points[0], &b = points[1], &c = points[2], &d = points[3];
        Point ab(a, b), ac(a, c);
        if (ab.isOrthogonalTo(ac) && ab.length2() == ac.length2() && a + ab + ac == d) {
            cout << "YES";
            return 0;
        }
    } while (next_permutation(points.begin(), points.end()));

    cout << "NO";
}