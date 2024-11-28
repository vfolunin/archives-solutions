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

    double length() const {
        return hypot(x, y);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    double angleTo(const Point &that) const {
        return acos(max(-1.0, min(1.0, dotProduct(that) / (length() * that.length()))));
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

vector<double> getAngles() {
    Point a, b, c;
    cin >> a >> b >> c;

    vector<double> angles = {
        Point(a, b).angleTo(Point(a, c)),
        Point(b, a).angleTo(Point(b, c)),
        Point(c, a).angleTo(Point(c, b))
    };

    sort(angles.begin(), angles.end());
    return angles;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<double> a = getAngles();
    vector<double> b = getAngles();

    for (int i = 0; i < a.size(); i++) {
        if (abs(a[i] - b[i]) > EPS) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}