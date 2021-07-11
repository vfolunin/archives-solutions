#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double k, l, h, m;
    cin >> k >> l >> h >> m;

    if (!k && !l && !h && !m)
        return 0;

    double g = 9.81, v;

    if (l >= h) {
        v = sqrt(2 * g * h);
    } else {
        double dl = l - h;
        double e = m * g * h - k * dl * dl / 2;

        if (e < 0) {
            cout << "Stuck in the air.\n";
            return 1;
        }

        v = sqrt(2 * e / m);
    }

    if (v > 10)
        cout << "Killed by the impact.\n";
    else
        cout << "James Bond survives.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}