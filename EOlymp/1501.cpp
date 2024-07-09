#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double PI = acos(-1);

bool solve() {
    double r, h, d1, a1, d2, a2;
    if (!(cin >> r >> h >> d1 >> a1 >> d2 >> a2))
        return 0;

    a1 *= PI / 180;
    a2 *= PI / 180;
    double a = fabs(a1 - a2);
    a = min(a, 2 * PI - a);

    a *= sin(atan2(r, h));
    double res = sqrt(d1 * d1 + d2 * d2 - 2 * d1 * d2 * cos(a));

    cout.precision(2);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}