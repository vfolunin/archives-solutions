#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getMinDivisorGreaterThan3(int n) {
    long long res = 1e18;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            if (d > 3)
                res = min(res, d);
            if (n / d > 3)
                res = min(res, n / d);
        }
    }
    return n ? res : 4;
}

bool solve() {
    int value;
    cin >> value;

    if (!value)
        return 0;

    long long res = getMinDivisorGreaterThan3(value - 3);

    if (res != 1e18)
        cout << res << "\n";
    else
        cout << "No such base\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}