#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double x1, y1, x2, y2, x3, y3;
    if (!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3))
        return 0;

    double a = x1 * (y2 - y3) - y1 * (x2 - x3) + x2 * y3 - x3 * y2;
    double b = (x1 * x1 + y1 * y1) * (y3 - y2) + (x2 * x2 + y2 * y2) * (y1 - y3) + (x3 * x3 + y3 * y3) * (y2 - y1);
    double c = (x1 * x1 + y1 * y1) * (x2 - x3) + (x2 * x2 + y2 * y2) * (x3 - x1) + (x3 * x3 + y3 * y3) * (x1 - x2);
    double d = (x1 * x1 + y1 * y1) * (x3 * y2 - x2 * y3) + (x2 * x2 + y2 * y2) * (x1 * y3 - x3 * y1) + (x3 * x3 + y3 * y3) * (x2 * y1 - x1 * y2);

    double x = -b / (2 * a);
    double y = -c / (2 * a);
    double r = sqrt((b * b + c * c - 4 * a * d) / (4 * a * a));

    cout.precision(3);
    cout << fixed;

    cout << "(x " << (x > 0 ? '-' : '+') << " " << fabs(x) << ")^2 + ";
    cout << "(y " << (y > 0 ? '-' : '+') << " " << fabs(y) << ")^2 = ";
    cout << r << "^2\n";

    b /= a;
    c /= a;
    d /= a;

    cout << "x^2 + y^2";
    cout << " " << (b > 0 ? '+' : '-') << " " << fabs(b) << "x";
    cout << " " << (c > 0 ? '+' : '-') << " " << fabs(c) << "y";
    cout << " " << (d > 0 ? '+' : '-') << " " << fabs(d) << " = 0\n\n";

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}