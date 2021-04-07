#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double length(double a, double b, double width) {
    double height = width / a * b;
    double radius = hypot(width, height) / 2;
    double angle = acos(-1) - 2 * atan2(width, height);
    return 2 * (width + radius * angle);
}

bool solve(int test) {
    double a, b;
    char colon;
    if (!(cin >> a >> colon >> b))
        return 0;

    double l = 0, r = 400;
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        if (length(a, b, m) <= 400)
            l = m;
        else
            r = m;
    }

    cout << "Case " << test << ": ";
    cout.precision(6);
    cout << fixed << l << " " << l / a * b << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}