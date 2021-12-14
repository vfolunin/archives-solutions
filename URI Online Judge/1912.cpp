#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<double> &strip, double targetArea, double y) {
    double area = 0;
    for (double &s : strip)
        area += max(0.0, s - y);
    return area >= targetArea;
}

bool solve() {
    int stripCount;
    double targetArea;
    cin >> stripCount >> targetArea;

    if (!stripCount && !targetArea)
        return 0;

    vector<double> strip(stripCount);
    double totalArea = 0;
    for (double &s : strip) {
        cin >> s;
        totalArea += s;
    }

    if (fabs(totalArea - targetArea) <= 1e-9) {
        cout << ":D\n";
        return 1;
    }

    double l = 0, r = 2e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (can(strip, targetArea, m))
            l = m;
        else
            r = m;
    }

    if (l < 1e-9) {
        cout << "-.-\n";
    } else {
        cout.precision(4);
        cout << fixed << l << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}