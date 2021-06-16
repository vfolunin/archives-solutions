#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 7477777;

long long binPow(long long x, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x % MOD;
    long long r = binPow(x, p / 2);
    return r * r % MOD;
}

long long inv(long long x) {
    return binPow(x, MOD - 2);
}

long long c(long long n, long long m) {
    long long res = 1;
    for (long long x = n; x > n - m; x--)
        res = res * x % MOD;
    for (long long x = 2; x <= m; x++)
        res = res * inv(x) % MOD;
    return res;
}

void solve(int test) {
    int n;
    cin >> n;

    long long res = 0;
    if (n >= 5) {
        n -= 5;
        res = c(n + 5, 5) * (n + 3) % MOD;
        res = res * inv(3) % MOD;
        res = res * 5 % MOD;
    }

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}