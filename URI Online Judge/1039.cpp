#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double r1, x1, y1, r2, x2, y2;
    if (!(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2))
        return 0;

    if (hypot(x1 - x2, y1 - y2) + r2 <= r1 + 1e-9)
        cout << "RICO\n";
    else
        cout << "MORTO\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}