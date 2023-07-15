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

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point o1, o2;
    double radius1, radius2;
    cin >> o1 >> radius1 >> o2 >> radius2;

    double o1o2Dist = o1.distanceTo(o2);
    double radiusDiff = abs(radius1 - radius2);

    if (radius1 + radius2 + EPS < o1o2Dist || o1o2Dist + EPS < radiusDiff)
        cout << "NO";
    else
        cout << "YES";
}