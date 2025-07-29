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

    long long a, b, c;
    cin >> a >> b >> c;

    const long long MOD = 1e9 + 7;
    if (binPow(a, binPow(b, c, MOD - 1), MOD) == binPow(binPow(a, b, MOD), c, MOD))
        cout << "What an excellent example!";
    else
        cout << "Oh look, a squirrel!";
}