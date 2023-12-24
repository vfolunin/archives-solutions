#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool f(double a, double b, double c, double d, double x) {
    return a * x * x * x + b * x * x + c * x + d < 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double l = -1e9, r = 1e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (f(a, b, c, d, m) == f(a, b, c, d, -1e9))
            l = m;
        else
            r = m;
    }

    cout << fixed << r;
}