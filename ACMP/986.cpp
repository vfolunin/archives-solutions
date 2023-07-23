#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

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

    int pointCount, radius;
    Point o;
    cin >> pointCount >> o >> radius;

    for (int i = 0; i < pointCount; i++) {
        Point point;
        cin >> point;

        if (o.distance2To(point) <= radius * radius) {
            cout << i + 1;
            return 0;
        }
    }

    cout << "Yes";
}