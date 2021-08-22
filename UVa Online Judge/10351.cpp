#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    double x1, y1, z1, x2, y2, z2;
    if (!(cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2))
        return 0;

    if (x1 < x2) {
        swap(x1, z1);
        swap(x2, z2);
    }
    if (y1 < y2) {
        swap(y1, z1);
        swap(y2, z2);
    }

    double res = 0;
    if (z1 < z2) {
        double d = z1 - (z2 - z1);
        double f = 1 - (d * d) / (z2 * z2);
        res = acos(-1) * x2 / 2 * y2 / 2 * f;
    }

    cout << "Set #" << test << "\n";
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}