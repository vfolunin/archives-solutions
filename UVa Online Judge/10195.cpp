#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double a, b, c;
    if (!(cin >> a >> b >> c))
        return 0;

    double p = (a + b + c) / 2;
    double r = p ? sqrt((p - a) * (p - b) * (p - c) / p) : 0;

    cout.precision(3);
    cout << "The radius of the round table is: " << fixed << r << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}