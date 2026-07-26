#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(double a, double b, double c, double value) {
    return value / a + value / b + value / c <= 1000;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b, c;
    cin >> a >> b >> c;

    double l = 0, r = 1;
    while (can(a, b, c, r))
        r *= 2;

    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (can(a, b, c, m))
            l = m;
        else
            r = m;
    }

    cout.precision(0);
    cout << fixed << l;
}