#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double l, w, h, theta;
    if (!(cin >> l >> w >> h >> theta))
        return 0;

    double volume = h * l * w;
    double h1 = l * tan(theta / 180 * acos(-1));
    double l1 = h * tan((90 - theta) / 180 * acos(-1));

    if (h1 <= h)
        volume -= h1 * l * w / 2;
    else
        volume = h * l1 * w / 2;

    cout.precision(3);
    cout << fixed << volume << " mL\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}