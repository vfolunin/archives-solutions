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

    bool operator == (const Point &that) const {
        return x == that.x && y == that.y;
    }

    int crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    bool isCollinearTo(const Point &that) const {
        return !crossProduct(that);
    }

    int distance2To(const Point &that) const {
        int dx = x - that.x;
        int dy = y - that.y;
        return dx * dx + dy * dy;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point a, b, c;
    cin >> a >> b >> c;

    if (a == b && a == c) {
        cout << 0;
    } else if (a == b || a == c || b == c) {
        cout << 1;
    } else if (Point(a, b).isCollinearTo(Point(a, c))) {
        cout << 2;
    } else {
        vector<int> sides = { a.distance2To(b), a.distance2To(c), b.distance2To(c) };
        sort(sides.begin(), sides.end());

        if (sides[0] + sides[1] > sides[2])
            cout << 3;
        else if (sides[0] + sides[1] == sides[2])
            cout << 4;
        else
            cout << 5;
    }
}