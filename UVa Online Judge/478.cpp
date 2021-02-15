#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double cross(const Point &that) const {
        return x * that.y - y * that.x;
    }

    int side(const Point &that) const {
        double c = cross(that);
        if (c > 0)
            return 1;
        if (c < 0)
            return -1;
        return 0;
    }
};

struct Figure {
    virtual bool contains(Point &p) = 0;
};

struct Rectangle : public Figure {
    Point a, b;

    bool contains(Point &p) {
        return a.x + EPS <= p.x && p.x <= b.x - EPS && a.y + EPS <= p.y && p.y <= b.y - EPS;
    }
};

struct Triangle : public Figure {
    Point a, b, c;

    bool contains(Point &p) {
        int sa = Point(a, b).side(Point(a, p));
        int sb = Point(b, c).side(Point(b, p));
        int sc = Point(c, a).side(Point(c, p));
        return sa == sb && sa == sc;
    }
};

struct Circle : public Figure {
    Point c;
    double r;

    bool contains(Point &p) {
        return hypot(p.x - c.x, p.y - c.y) <= r - EPS;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Figure *> figures;
    while (1) {
        char type;
        cin >> type;

        if (type == 'r') {
            Rectangle *r = new Rectangle;
            cin >> r->a.x >> r->b.y >> r->b.x >> r->a.y;
            figures.push_back(r);
        } else if (type == 't') {
            Triangle *t = new Triangle;
            cin >> t->a.x >> t->a.y >> t->b.x >> t->b.y >> t->c.x >> t->c.y;
            figures.push_back(t);
        } else if (type == 'c') {
            Circle *c = new Circle;
            cin >> c->c.x >> c->c.y >> c->r;
            figures.push_back(c);
        } else {
            break;
        }
    }

    for (int pi = 0; 1; pi++) {
        Point p;
        cin >> p.x >> p.y;

        if (p.x == 9999.9 && p.y == 9999.9)
            break;

        bool found = 0;
        for (int fi = 0; fi < figures.size(); fi++) {
            if (figures[fi]->contains(p)) {
                cout << "Point " << pi + 1 << " is contained in figure " << fi + 1 << "\n";
                found = 1;
            }
        }

        if (!found)
            cout << "Point " << pi + 1 << " is not contained in any figure\n";
    }
}