#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double angle, dist, height;
    if (!(cin >> angle >> dist >> height))
        return 0;

    angle *= 3.141592654 / 180;

    cout.precision(2);
    cout << fixed << 5 * (tan(angle) * dist + height) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}