#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double a = -1, b = -1, c;
    if (!(cin >> c))
        return 0;

    double d = b * b - 4 * a * c;
    double r = (-b - sqrt(d)) / (2 * a);

    cout.precision(2);
    cout << fixed << r << " ";
    cout.precision(0);
    cout << fixed << floor(r + 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}