#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double carLen, carAcc;
    cin >> carLen >> carAcc;

    if (!carLen && !carAcc)
        return 0;

    double speed = sqrt(2 * carLen * carAcc);
    double volume = speed * 1800 / carLen;

    cout.precision(8);
    cout << fixed << speed << " " << volume << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}