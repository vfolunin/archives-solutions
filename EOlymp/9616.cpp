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

void solve() {
    int size, letterCount;
    cin >> size >> letterCount;

    const long long MOD = 1e9 + 7;
    long long res = letterCount;

    if (size >= 2)
        res = res * (letterCount - 1) % MOD;

    if (size >= 3)
        res = res * binPow(letterCount - 2, size - 2, MOD) % MOD;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}