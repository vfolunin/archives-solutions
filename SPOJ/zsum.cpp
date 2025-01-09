#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

bool solve() {
    int n, k;
    cin >> n >> k;

    if (!n)
        return 0;

    const long long MOD = 1e7 + 7;

    cout << (binPow(n, k, MOD) + 2 * binPow(n - 1, k, MOD) + binPow(n, n, MOD) + 2 * binPow(n - 1, n - 1, MOD)) % MOD << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}