#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double x1, y1, x2, y2, p;
    if (!(cin >> x1 >> y1 >> x2 >> y2 >> p))
        return 0;

    double dx = fabs(x1 - x2);
    double dy = fabs(y1 - y2);

    cout << fixed << pow(pow(dx, p) + pow(dy, p), 1 / p) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}