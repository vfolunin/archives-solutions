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

long long inv(long long x, long long mod) {
    return binPow(x, mod - 2, mod);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int letterCount, size;
    cin >> letterCount >> size;

    const long long MOD = 1e9 + 7;
    long long res = (binPow(letterCount, size + 1, MOD) - 1 + MOD) % MOD;
    res = res * inv(letterCount - 1, MOD) % MOD;
    res = (res - 1 + MOD) % MOD;

    cout << res;
}