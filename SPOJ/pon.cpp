#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

long long binMul(long long a, long long b, long long mod) {
    if (!b)
        return 0;
    if (b % 2)
        return (binMul(a, b - 1, mod) + (a % mod)) % mod;
    long long r = binMul(a, b / 2, mod);
    return (r + r) % mod;
}

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1 % mod;
    if (p % 2)
        return binMul(binPow(x, p - 1, mod), x, mod);
    long long r = binPow(x, p / 2, mod);
    return binMul(r, r, mod);
}

bool millerRabin(long long n) {
    if (n < 2 || n > 3 && n % 2 == 0)
        return 0;
    if (n == 2 || n == 3)
        return 1;

    long long s = 0, t = n - 1;
    while (t % 2 == 0) {
        t /= 2;
        s++;
    }

    for (int i = 0; i < 50; i++) {
        static minstd_rand gen;
        long long a = uniform_int_distribution<long long>(2, n - 2)(gen);
        long long x = binPow(a, t, n);

        if (x == 1 || x == n - 1)
            continue;

        for (int j = 0; x != n - 1 && j < s - 1; j++) {
            x = binMul(x, x, n);
            if (x == 1)
                return 0;
        }

        if (x != n - 1)
            return 0;
    }

    return 1;
}

void solve() {
    long long n;
    cin >> n;

    cout << (millerRabin(n) ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}