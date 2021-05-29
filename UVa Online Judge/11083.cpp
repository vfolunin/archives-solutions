#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long maxDivisor(long long n) {
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0)
            n /= d;
        if (n == 1)
            return d;
    }
    return n;
}

bool solve() {
    long long n, base;
    cin >> n >> base;

    if (!n && !base)
        return 0;

    long long d = maxDivisor(base), res = 0;
    for (long long power = d; power < n; power *= d) {
        res += (n / power) * (n / power - 1) / 2 * power;
        res += (n / power) * (n % power + 1);
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}