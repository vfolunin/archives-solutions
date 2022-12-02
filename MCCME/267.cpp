#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    double angle() const {
        double a = atan2(y, x);
        if (a < -EPS)
            a += 2 * acos(-1.0);
        return a;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    Point p;
    cin >> p;

    cout << fixed << p.angle();
}