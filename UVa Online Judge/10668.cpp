#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double chord, dt, coeff;
    cin >> chord >> dt >> coeff;

    if (chord < 0)
        return 0;

    double arc = chord * (coeff * dt + 1);

    double l = 0, r = acos(-1);
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        double radius = (chord / 2) / sin(m);
        if (radius * 2 * m < arc)
            l = m;
        else
            r = m;
    }

    double res = l ? (chord / 2) / sin(l) * (1 - cos(l)) : 0;

    cout.precision(3);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}