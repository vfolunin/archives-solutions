#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long phi(long long n) {
    long long res = n;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            while (n % d == 0)
                n /= d;
            res -= res / d;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1 % mod;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

void solve() {
    int n, mod;
    cin >> n >> mod;

    int res = 0;
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            res = (res + phi(d) * binPow(n, n / d - 1, mod)) % mod;
            if (d * d < n)
                res = (res + phi(n / d) * binPow(n, d - 1, mod)) % mod;
        }
    }

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