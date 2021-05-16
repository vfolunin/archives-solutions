#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double triangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double quadrilateralArea(double a, double b, double c, double d, double diag) {
    return triangleArea(a, b, diag) + triangleArea(c, d, diag);
}

double radius(double a, double b, double c, double d, double diag) {
    return quadrilateralArea(a, b, c, d, diag) * 2 / (a + b + c + d);
}

void solve(int test) {
    double perimeter, a, b;
    cin >> perimeter >> a >> b;

    cout << "Case " << test << ": ";

    if (a >= perimeter / 2 || b >= perimeter / 2) {
        cout << "Eta Shombhob Na.\n";
        return;
    }

    if (a > b)
        swap(a, b);
    double c = perimeter / 2 - a, d = perimeter / 2 - b;

    double l = max(b - a, d - c), r = min(a + b, c + d);
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3, rad1 = radius(a, b, c, d, m1);
        double m2 = r - (r - l) / 3, rad2 = radius(a, b, c, d, m2);
        if (rad1 < rad2)
            l = m1;
        else
            r = m2;
    }

    cout.precision(6);
    cout << fixed << radius(a, b, c, d, l) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}