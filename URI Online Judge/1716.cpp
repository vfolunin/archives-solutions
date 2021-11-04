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

long long gcdex(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1, d = gcdex(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

bool solve() {
    long long n, e, msg;
    if (!(cin >> n >> e >> msg))
        return 0;

    long long a = 2;
    while (n % a)
        a++;
    long long b = n / a;

    long long phi = (a - 1) * (b - 1);

    long long x, y;
    gcdex(e, phi, x, y);
    long long d = (x % phi + phi) % phi;

    cout << binPow(msg, d, n) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}