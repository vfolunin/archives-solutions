#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double radius, angle;
    string unit;
    if (!(cin >> radius >> angle >> unit))
        return 0;

    radius += 6440;

    double full = (unit == "deg" ? 360 : 360 * 60);
    angle -= floor(angle / full) * full;
    angle = min(angle, full - angle);
    angle *= acos(-1.0) / (full / 2);

    double arc = radius * angle;
    double chord = 2 * radius * sin(angle / 2);

    cout << fixed << arc << " " << chord << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}