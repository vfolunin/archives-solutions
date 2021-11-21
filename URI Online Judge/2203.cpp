#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int x1, y1, x2, y2, v, ra, rb;
    if (!(cin >> x1 >> y1 >> x2 >> y2 >> v >> ra >> rb))
        return 0;

    double dist = hypot(x1 - x2, y1 - y2) + 1.5 * v;

    cout << (dist > ra + rb + 1e-9 ? "N\n" : "Y\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}