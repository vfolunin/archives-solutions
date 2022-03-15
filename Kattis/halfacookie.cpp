#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double radius, x, y;
    if (!(cin >> radius >> x >> y))
        return 0;

    double distance = hypot(x, y);
    if (distance > radius) {
        cout << "miss\n";
        return 1;
    }

    double angle = 2 * acos(distance / radius);
    double areaA = radius * radius / 2 * (angle - sin(angle));
    double areaB = acos(-1) * radius * radius - areaA;
    if (areaA < areaB)
        swap(areaA, areaB);

    cout << fixed << areaA << " " << areaB << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}