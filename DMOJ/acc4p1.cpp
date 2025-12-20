#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double f(double x) {
    return 12 * x * x - 5 * x + 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double limit;
    cin >> limit;

    double l = 5 / 12., r = 1;
    while (f(r) < limit)
        r *= 2;

    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (f(m) < limit)
            l = m;
        else
            r = m;
    }

    cout << fixed << r;
}