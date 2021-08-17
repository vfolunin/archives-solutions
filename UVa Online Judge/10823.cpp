#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;
};

struct Color {
    int r, g, b;
};

struct Figure {
    Point coord;
    int size;
    Color color;
    virtual bool contains(Point &p) = 0;
    virtual bool containsOnBorder(Point &p) = 0;
};

struct Square : public Figure {
    bool contains(Point &p) {
        return coord.x < p.x && p.x < coord.x + size &&
               coord.y < p.y && p.y < coord.y + size;
    }
    bool containsOnBorder(Point &p) {
        return (coord.x == p.x || coord.x + size == p.x) && coord.y <= p.y && p.y <= coord.y + size ||
               (coord.y == p.y || coord.y + size == p.y) && coord.x <= p.x && p.x <= coord.x + size;
    }
};

struct Circle : public Figure {
    bool contains(Point &p) {
        int dx = coord.x - p.x, dy = coord.y - p.y;
        return dx * dx + dy * dy < size * size;
    }
    bool containsOnBorder(Point &p) {
        int dx = coord.x - p.x, dy = coord.y - p.y;
        return dx * dx + dy * dy == size * size;
    }
};

int divRound(int a, int b) {
    return a / b + (a % b >= (b + 1) / 2);
}

void solve(int test) {
    int figureCount, pointCount;
    cin >> figureCount >> pointCount;

    vector<Figure *> figures(figureCount);
    for (Figure *&f : figures) {
        string type;
        cin >> type;

        if (type == "SQUARE")
            f = new Square;
        else
            f = new Circle;
        cin >> f->coord.x >> f->coord.y >> f->size >> f->color.r >> f->color.g >> f->color.b;
    }

    if (test > 1)
        cout << "\n";
    cout << "Case " << test << ":\n";

    for (int i = 0; i < pointCount; i++) {
        Point p;
        cin >> p.x >> p.y;

        Color res = { 0, 0, 0 };
        int containers = 0;

        for (Figure *f : figures) {
            if (f->containsOnBorder(p)) {
                containers = -1;
                break;
            } else if (f->contains(p)) {
                containers++;
                res.r += f->color.r;
                res.g += f->color.g;
                res.b += f->color.b;
            }
        }

        if (containers > 0) {
            res.r = divRound(res.r, containers);
            res.g = divRound(res.g, containers);
            res.b = divRound(res.b, containers);
        } else if (containers == -1) {
            res = { 0, 0, 0 };
        } else {
            res = { 255, 255, 255 };
        }

        cout << "(" << res.r << ", " << res.g << ", " << res.b << ")\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}