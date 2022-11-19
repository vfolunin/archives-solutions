#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    double distanceTo(Point &that) {
        return hypot(x - that.x, y - that.y);
    }
};

double perimeter(Point &a, Point &b, Point &c) {
    return a.distanceTo(b) + b.distanceTo(c) + c.distanceTo(a);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto &p : points)
        cin >> p.x >> p.y;

    double res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                res = max(res, perimeter(points[i], points[j], points[k]));

    cout.precision(15);
    cout << res;
}