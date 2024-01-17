#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double l, r, delta;
    cin >> l >> r >> delta;

    for (double x = l; x <= r; x += delta)
        cout << fixed << x << " " << 3 * sin(x) << "\n";
}