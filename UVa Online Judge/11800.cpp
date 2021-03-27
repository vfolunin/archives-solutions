#include <iostream>
#include <algorithm>
#include <cmath>
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

    int crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    bool isCollinearTo(const Point &that) const {
        return !crossProduct(that);
    }
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

bool square(Point &a, Point &b, Point &c, Point &d) {
    Point ab(a, b), ac(a, c), bd(b, d), cd(c, d);
    return ab.length2() == ac.length2() &&
        ab.length2() == bd.length2() &&
        ab.length2() == cd.length2() &&
        ab.isOrthogonalTo(ac) &&
        ab.isOrthogonalTo(bd) &&
        ac.isOrthogonalTo(cd) &&
        bd.isOrthogonalTo(cd);
}

bool rectangle(Point &a, Point &b, Point &c, Point &d) {
    Point ab(a, b), ac(a, c), bd(b, d), cd(c, d);
    return ab.length2() == cd.length2() &&
        ac.length2() == bd.length2() &&
        ab.isOrthogonalTo(ac) &&
        ab.isOrthogonalTo(bd) &&
        ac.isOrthogonalTo(cd) &&
        bd.isOrthogonalTo(cd);
}

bool rhombus(Point &a, Point &b, Point &c, Point &d) {
    Point ab(a, b), ac(a, c), bd(b, d), cd(c, d);
    return ab.length2() == ac.length2() &&
        ab.length2() == bd.length2() &&
        ab.length2() == cd.length2();
}

bool parallelogram(Point &a, Point &b, Point &c, Point &d) {
    Point ab(a, b), ac(a, c), bd(b, d), cd(c, d);
    return ab.isCollinearTo(cd) && ac.isCollinearTo(bd);
}

bool trapezium(Point &a, Point &b, Point &c, Point &d) {
    Point ab(a, b), ac(a, c), bd(b, d), cd(c, d);
    return ab.isCollinearTo(cd) || ac.isCollinearTo(bd);
}

template<typename F>
bool check(vector<Point> &points, F f) {
    sort(points.begin(), points.end());
    do {
        if (f(points[0], points[1], points[2], points[3]))
            return 1;
    } while (next_permutation(points.begin(), points.end()));
    return  0;
}

void solve(int test) {
    vector<Point> points(4);
    for (Point &p : points)
        cin >> p;

    cout << "Case " << test << ": ";
    if (check(points, square))
        cout << "Square\n";
    else if (check(points, rectangle))
        cout << "Rectangle\n";
    else if (check(points, rhombus))
        cout << "Rhombus\n";
    else if (check(points, parallelogram))
        cout << "Parallelogram\n";
    else if (check(points, trapezium))
        cout << "Trapezium\n";
    else
        cout << "Ordinary Quadrilateral\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}