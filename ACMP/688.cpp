#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    long long x, y;

    long long distance2To(const Point &that) const {
        long long dx = x - that.x;
        long long dy = y - that.y;
        return dx * dx + dy * dy;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point a, b;
    cin >> a >> b;

    int pointCount;
    cin >> pointCount;

    for (int i = 0; i < pointCount; i++) {
        Point p;
        cin >> p;

        if (a.distance2To(p) * 4 <= b.distance2To(p)) {
            cout << i + 1;
            return 0;
        }
    }

    cout << "NO";
}