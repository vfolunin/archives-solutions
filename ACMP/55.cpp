#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double x1, y1, x2, y2, radius, area;
    cin >> x1 >> y1 >> x2 >> y2 >> radius >> area;

    double area2 = 2 * acos(-1) * radius * radius;
    double dist = hypot(x1 - x2, y1 - y2);

    if (dist <= 2 * radius) {
        double angle = acos(dist / 2 / radius);
        area2 -= (2 * radius * angle - dist * sin(angle)) * radius;
    }

    cout << (area2 > area ? "YES" : "NO");
}