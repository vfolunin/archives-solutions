#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int factPower(int f, int p) {
    int res = 0;
    while (f) {
        f /= p;
        res += f;
    }
    return res;
}

int zeroCount(int n, int base) {
    int res = 1e9;

    for (int d = 2; d * d <= base; d++) {
        if (base % d)
            continue;

        int power = 0;
        while (base % d == 0) {
            base /= d;
            power++;
        }

        res = min(res, factPower(n, d) / power);
    }
    if (base > 1)
        res = min(res, factPower(n, base));

    return res;
}

int digitCount(int n, int base) {
    double logSum = 0;
    for (int i = 1; i <= n; i++)
        logSum += log10(i);
    return floor(logSum / log10(base) + 1e-9) + 1;
}

bool solve() {
    int n, base;
    if (!(cin >> n >> base))
        return 0;

    cout << zeroCount(n, base) << " " << digitCount(n, base) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}