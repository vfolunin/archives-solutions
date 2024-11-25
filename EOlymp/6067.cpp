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

void solve() {
    long long n;
    int p;
    cin >> n >> p;

    const long long MOD = 1e9 + 7;

    if (p == 1)
        cout << n * (n + 1) % MOD * inv(2, MOD) % MOD << "\n";
    else if (p == 2)
        cout << n * (n + 1) % MOD * (2 * n + 1) % MOD * inv(6, MOD) % MOD << "\n";
    else if (p == 3)
        cout << n * n % MOD * (n + 1) % MOD * (n + 1) % MOD * inv(4, MOD) % MOD << "\n";
    else
        cout << n * (n + 1) % MOD * (2 * n + 1) % MOD * ((3 * n * n + 3 * n - 1) % MOD) % MOD * inv(30, MOD) % MOD << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}