#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double w, h, t, xColl, yColl;
    cin >> w >> h >> t >> xColl >> yColl;

    if (!w && !h)
        return 0;

    double x = w * xColl, y = h * yColl;
    double a = atan2(y, x) / acos(-1) * 180;
    double v = hypot(x, y) / t;

    cout.precision(2);
    cout << fixed << a << " " << v << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}