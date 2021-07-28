#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double d, l, x1, y1, x2, y2;
    if (!(cin >> d >> l >> x1 >> y1 >> x2 >> y2))
        return 0;

    double stripes = fabs(floor(y1 / d) - floor(y2 / d));
    double swim = stripes * 2 * l;
    double walk = hypot(fabs(x1 - x2), fabs(y1 - y2) - swim);

    cout.precision(2);
    cout << "The gopher has to swim " << fixed << swim;
    cout << " meters and walk " << fixed << walk << " meters.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}