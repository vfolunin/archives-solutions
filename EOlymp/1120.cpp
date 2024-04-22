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

    int length2() const {
        return x * x + y * y;
    }

    int dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    bool isOrthogonalTo(const Point &that) const {
        return !dotProduct(that);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

string getType(vector<Point> &points) {
    bool lengths = 1;
    bool angles = 1;

    for (int i = 0; i < 4; i++) {
        Point &a = points[i];
        Point &b = points[(i + 1) % points.size()];
        Point &c = points[(i + 2) % points.size()];
        Point ab(a, b);
        Point bc(b, c);

        lengths &= ab.length2() == bc.length2();
        angles &= ab.isOrthogonalTo(bc);
    }

    if (lengths && angles)
        return "Square";
    else if (lengths)
        return "Rhombus";
    else if (angles)
        return "Rectangle";
    else
        return "Other";
}

void solve(int test) {
    vector<Point> points(4);
    for (Point &point : points)
        cin >> point;

    cout << "Case " << test << ": " << getType(points) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}