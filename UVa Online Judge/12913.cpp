#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

long long inv(long long x) {
    return binPow(x, MOD - 2, MOD);
}

vector<long long> getF() {
    vector<long long> f(1e6 + 1);
    f[0] = 1;
    for (int i = 1; i < f.size(); i++)
        f[i] = f[i - 1] * i % MOD;
    return f;
}

long long c(int n, int m) {
    static vector<long long> f = getF();
    return f[n] * inv(f[m]) % MOD * inv(f[n - m]) % MOD;
}

bool solve() {
    int n, k;
    if (!(cin >> n >> k))
        return 0;

    long long phi = MOD - 1;
    long long p = (binPow(2, n, phi) + phi - n) % phi;
    long long res = c(n, k) * binPow(2, p, MOD) % MOD;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}