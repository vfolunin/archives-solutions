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

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator == (const Point &that) const {
        return x == that.x && y == that.y;
    }

    bool operator < (const Point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    bool isOrthogonalTo(const Point &that) const {
        return !dotProduct(that);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }

    friend ostream &operator << (ostream &out, const Point &p) {
        return out << p.x << " " << p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  
    vector<Point> points(3);
    for (Point &point : points)
        cin >> point;

    sort(points.begin(), points.end());

    do {
        Point ab(points[0], points[1]);
        Point ac(points[0], points[2]);
        if (ab.isOrthogonalTo(ac)) {
            cout << points[0] + ab + ac;
            break;
        }
    } while (next_permutation(points.begin(), points.end()));
}