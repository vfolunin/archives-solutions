#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getValue(int n) {
    string s;
    for (; n > 1; n /= 2)
        s += n % 2 ? '7' : '4';
    reverse(s.begin(), s.end());
    return stoll(s);
}

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

    long long l, r;
    cin >> l >> r;

    const long long MOD = 1234567891;
    long long res = 0;

    for (int n = 2; 1; n++) {
        long long value = getValue(n);
        if (r < value)
            break;
        if (l <= value)
            res = (res + binPow(value % MOD, value, MOD)) % MOD;
    }

    cout << res;
}