#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    double height, volume;
    cin >> height >> volume;

    height *= 2;
    volume *= 282;

    static const double PI = acos(-1);

    double l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        double v = 7 * PI * m * m * height / 24;
        if (v < volume)
            l = m;
        else
            r = m;
    }

    cout.precision(3);
    cout << "Case " << test << ": " << fixed << l * 2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}