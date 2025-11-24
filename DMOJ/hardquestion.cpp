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

    double g, c, t;
    cin >> g >> c >> t;

    double l = 0, r = 1e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (sqrt(2 * m / g) + m / c < t)
            l = m;
        else
            r = m;
    }

    cout << fixed << r << "\n" << g * sqrt(2 * r / g);
}