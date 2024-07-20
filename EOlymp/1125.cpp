#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, m;
    cin >> h >> m;

    if (!h && !m)
        return 0;

    double a = (h * 60 + m) % (12 * 60) * 0.5;
    double b = m * 6.0;
    double res = abs(a - b);
    res = min(res, 360 - res);

    cout << "At " << h << ":" << setw(2) << setfill('0') << m;
    cout << " the angle is " << fixed << setprecision(1) << res << " degrees.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}