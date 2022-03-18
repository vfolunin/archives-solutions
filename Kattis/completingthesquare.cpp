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

    bool operator < (const Point &that) const {
        return x < that.x || x == that.x && y < that.y;
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    int dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    bool isOrthogonalTo(const Point &that) const {
        return !dotProduct(that);
    }
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

ostream &operator << (ostream &out, const Point &p) {
    out << p.x << " " << p.y;
    return out;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Point> p(3);
    cin >> p[0] >> p[1] >> p[2];

    sort(p.begin(), p.end());
    while (!Point(p[0], p[1]).isOrthogonalTo(Point(p[0], p[2])))
        next_permutation(p.begin(), p.end());

    Point ab(p[0], p[1]), ac(p[0], p[2]);
    
    cout << p[0] + ab + ac;
}