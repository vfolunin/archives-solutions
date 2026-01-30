#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y, z;

    Point(double radius, double lat, double lon) {
        lat *= acos(-1) / 180;
        lon *= acos(-1) / 180;

        x = radius * cos(lat) * cos(lon);
        y = radius * cos(lat) * sin(lon);
        z = radius * sin(lat);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y + z * that.z;
    }

    double length() const {
        return hypot(x, y, z);
    }

    double angleTo(const Point &that) const {
        return acos(clamp(dotProduct(that) / (length() * that.length()), -1.0, 1.0));
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double radius, lat1, lon1, lat2, lon2;
    cin >> radius >> lat1 >> lon1 >> lat2 >> lon2;

    cout.precision(2);
    cout << fixed << radius * Point(radius, lat1, lon1).angleTo(Point(radius, lat2, lon2));
}