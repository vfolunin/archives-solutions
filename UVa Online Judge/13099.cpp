#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double xl, yl, xr, yr;
    if (!(cin >> xl >> yl >> xr >> yr))
        return 0;

    double dx = xr - xl;
    double dy = yr - yl;
    double res = (dx * dx + dy * dy) / 6;

    cout.precision(8);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}