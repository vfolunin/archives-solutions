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

bool solve() {
    int n;
    cin >> n;

    if (n < 0)
        return 0;

    if (binPow(2, n - 1, n) == 1)
        cout << n << " is a Jimmy-number\n";
    else
        cout << n << " is not a Jimmy-number\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}