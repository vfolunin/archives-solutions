#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double toRad(double angle) {
    return angle / 180 * acos(-1);
}

double ctg(double angle) {
    return 1 / tan(angle);
}

bool solve() {
    double ax, ay, bx, by, angle1, angle2;
    if (!(cin >> ax >> ay >> bx >> by >> angle1 >> angle2))
        return 0;

    double res = hypot(ax - bx, ay - by) * (ctg(toRad(angle1)) + ctg(toRad(angle2)));

    cout.precision(3);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}