#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point rotate(double angle) const {
        return Point(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
    }    
};

void solve(int test) {
    int n;
    Point p, v;
    cin >> n >> v.x >> p.x >> p.y;

    double angle = acos(-1) * (1 - (n - 2.0) / n);

    if (test > 1)
        cout << "\n";
    cout << "Case #" << test << ":\n";
    for (int i = 0; i < n; i++) {
        cout << fixed << p.x << " " << p.y << "\n";
        p = p + v;
        v = v.rotate(angle);
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