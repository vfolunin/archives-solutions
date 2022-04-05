#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double d, s;
    cin >> d >> s;

    double l = 0, r = 1e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (m + s < m * cosh(d / (2 * m)))
            l = m;
        else
            r = m;
    }

    cout << fixed << 2 * l * sinh(d / (2 * l));
}