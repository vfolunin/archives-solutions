#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double a;
    if (!(cin >> a))
        return 0;

    double pi = acos(-1.0);
    double z = a * a * (1 - pi / 6 - sqrt(3.0) / 4);
    double y = a * a - pi * a * a / 4 - 2 * z;
    double x = a * a - 4 * y - 4 * z;

    cout.precision(3);
    cout << fixed << x << " " << 4 * y << " " << 4 * z << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}