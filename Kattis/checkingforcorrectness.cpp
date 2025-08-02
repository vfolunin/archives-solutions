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

bool solve() {
    long long a, b;
    char op;
    if (!(cin >> a >> op >> b))
        return 0;

    const int MOD = 1e4;
    if (op == '+')
        cout << (a + b) % MOD << "\n";
    else if (op == '*')
        cout << a % MOD * b % MOD << "\n";
    else
        cout << binPow(a % MOD, b, MOD) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}