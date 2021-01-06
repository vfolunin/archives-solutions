#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double f(double k[], double x) {
    return k[0] * exp(-x) + k[1] * sin(x) + k[2] * cos(x) + k[3] * tan(x) + k[4] * x * x + k[5];
}

bool solve() {
    double k[6];
    if (!(cin >> k[0] >> k[1] >> k[2] >> k[3] >> k[4] >> k[5]))
        return 0;

    double l = 0, r = 1;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (f(k, m) > 0)
            l = m;
        else
            r = m;
    }

    cout.precision(4);
    if (fabs(f(k, l)) < 1e-9)
        cout << fixed << l << "\n";
    else
        cout << "No solution\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}