#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double PI = acos(-1);

bool solve() {
    double diameter, distA;
    cin >> diameter >> distA;

    if (!diameter && !distA)
        return 0;

    double radius = diameter / 2;
    double ya = distA * sin(PI / 4);
    if (ya > radius) {
        cout << "INCORRECT INFORMATION !!!\n";
        return 1;
    }
    double angleA = asin(ya / radius);
    double xa = radius * cos(angleA);
    double xb = xa - distA * cos(PI / 4);
    double yb = 0;

    double l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        double xc = xb - m * cos(PI / 4), yc = yb - m * cos(PI / 4);
        if (hypot(xc, yc) < radius)
            l = m;
        else
            r = m;
    }
    double distC = l;

    cout << fixed << distC << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}