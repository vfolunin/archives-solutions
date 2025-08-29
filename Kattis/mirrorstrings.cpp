#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1 % mod;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    const long long MOD = 1e9 + 7;
    long long res = 0;
    for (int size = l; size <= r; size++)
        res = (res + binPow(2, (size + 1) / 2, MOD) + binPow(5, (size + 1) / 2, MOD)) % MOD;

    cout << res;
}