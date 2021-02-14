#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    bool operator == (const Point &that) const {
        return x == that.x && y == that.y;
    }

    Point operator + (const Point &that) const {
        return { x + that.x, y + that.y };
    }

    Point operator - (const Point &that) const {
        return { x - that.x, y - that.y };
    }
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

ostream &operator << (ostream &out, const Point &p) {
    out.precision(3);
    out << fixed << p.x << " " << p.y;
    return out;
}

bool solve() {
    Point a, b, a2, c;
    if (!(cin >> a >> b >> a2 >> c))
        return 0;

    if (b == a2) {
        swap(a, b);
    } else if (a == c) {
        swap(a2, c);
    } else if (b == c) {
        swap(a, b);
        swap(a2, c);
    }

    Point d = b + (c - a);
    cout << d << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}