#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double radius, distance, percent;
    cin >> radius >> distance >> percent;

    if (!radius)
        return 0;

    double circleLength = 2 * acos(-1) * radius;
    double tangentLength = sqrt(distance * distance - radius * radius);
    double arcLength = 2 * acos(radius / distance) * radius;

    cout.precision(2);
    cout << fixed << (circleLength - arcLength + 2 * tangentLength) * (1 + percent / 100) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}