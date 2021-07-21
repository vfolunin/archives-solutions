#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    char c1, c2;
    double v1, v2;
    if (!(cin >> c1 >> v1 >> c2 >> v2))
        return 0;

    if (c1 > c2) {
        swap(c1, c2);
        swap(v1, v2);
    }

    double d, h, t;
    if (c1 == 'D' && c2 == 'H') {
        d = v1;
        h = v2;
        double e = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (d + 273.16))));
        double n = 0.5555 * (e - 10.0);
        t = h - n;
    } else if (c1 == 'D' && c2 == 'T') {
        d = v1;
        t = v2;
        double e = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (d + 273.16))));
        double n = 0.5555 * (e - 10.0);
        h = t + n;
    } else {
        h = v1;
        t = v2;
        double n = h - t;
        double e = n / 0.5555 + 10;
        d = 1 / ((1 / 273.16) - log(e / 6.11) / 5417.7530) - 273.16;
    }

    cout.precision(1);
    cout << "T " << fixed << t << " ";
    cout << "D " << fixed << d << " ";
    cout << "H " << fixed << h << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}