#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double lensArea(double r1, double r2) {
    return r1 * r1 * acos(1 - (r2 * r2) / (2 * r1 * r1)) +
           r2 * r2 * acos((r2 * r2) / (2 * r1 * r2)) -
           0.5 * sqrt((2 * r1 + r2) * (2 * r1 - r2) * r2 * r2);
}

void solve(int test) {
    double r1, part;
    cin >> r1 >> part;

    double area = part * acos(-1) * r1 * r1, l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        if (lensArea(r1, m) < area)
            l = m;
        else
            r = m;
    }

    if (test)
        cout << "\n";
    cout.precision(0);
    cout << "R = " << fixed << r1 << ", ";
    cout.precision(2);
    cout << "P = " << fixed << part << ", ";
    cout << "Rope = " << fixed << l << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}