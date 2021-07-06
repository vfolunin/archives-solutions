#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double cylinderVolume(double r, double h) {
    return acos(-1) * r * r * h;
}

double bicylinderVolume(double r) {
    return r * r * r * 16 / 3;
}

bool solve() {
    double r, h;
    if (!(cin >> r >> h))
        return 0;

    double res = 2 * cylinderVolume(r, h);
    res -= bicylinderVolume(r);
    if (h / 2 < r)
        res += bicylinderVolume(sqrt(r * r - h * h / 4));

    cout.precision(4);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}