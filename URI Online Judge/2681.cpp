#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 24 * 60 * 60;

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
        return 1;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string n;
    cin >> n;

    long long t;
    if (n.size() < 5) {
        t = binPow(2, stoi(n), MOD);
    } else {
        long long phiMod = phi(MOD), p = 0;
        for (char d : n)
            p = (p * 10 + d - '0') % phiMod;
        t = binPow(2, phiMod + p, MOD);
    }
    t = (t + MOD - 1) % MOD;

    cout << setw(2) << setfill('0') << t / 3600 << ":";
    cout << setw(2) << setfill('0') << t % 3600 / 60 << ":";
    cout << setw(2) << setfill('0') << t % 60 << "\n";
}