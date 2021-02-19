#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double d, v;
    cin >> d >> v;

    if (!d && !v)
        return 0;

    double res = pow(pow(d, 3) - 6 * v / acos(-1), 1.0 / 3);

    cout.precision(3);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}