#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double height, dist, angle;
    if (!(cin >> height >> dist >> angle))
        return 0;

    angle = (angle - 90) / 180 * acos(-1);
    height += tan(angle) * dist;

    cout.precision(4);
    cout << fixed << height << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}