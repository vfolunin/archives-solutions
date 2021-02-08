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