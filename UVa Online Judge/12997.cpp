#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getNum(double xl, double xr, double y, double width) {
    double a = hypot(xl, y);
    double b = hypot(xr, y);
    double len = a + b + width;
    return (len * len / 2 - a * a - b * b) / (2 * width);
}

void solve(int test) {
    double y, r, l, width;
    cin >> y >> r >> l >> width;

    double num = 0, den = 0;
    if (l + width == r) {
        num = getNum(l, r, y, width);
        den = 1;
    } else {
        double dx = (r - l - width) / 1000;
        for (double xl = l + dx / 2, xr = xl + width; xr <= r + 1e-9; xl += dx, xr += dx) {
            num += getNum(xl, xr, y, width);
            den++;
        }
    }

    cout << "Case " << test << ": " << fixed << num / den << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}