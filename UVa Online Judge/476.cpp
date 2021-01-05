#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

struct Rectangle {
    Point a, b;

    bool contains(const Point &p) const {
        return a.x < p.x && p.x < b.x && a.y < p.y && p.y < b.y;
    }
};

istream &operator >> (istream &in, Rectangle &r) {
    in >> r.a >> r.b;
    swap(r.a.y, r.b.y);
    return in;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Rectangle> rectangles;
    char c;

    while (1) {
        cin >> c;
        if (c != 'r')
            break;

        rectangles.emplace_back();
        cin >> rectangles.back();
    }

    for (int pi = 0; 1; pi++) {
        Point p;
        cin >> p;
        if (p.x == 9999.9 && p.y == 9999.9)
            break;

        bool hasOutput = 0;
        for (int ri = 0; ri < rectangles.size(); ri++) {
            if (rectangles[ri].contains(p)) {
                cout << "Point " << pi + 1 << " is contained in figure " << ri + 1 << "\n";
                hasOutput = 1;
            }
        }
        if (!hasOutput)
            cout << "Point " << pi + 1 << " is not contained in any figure\n";
    }
}