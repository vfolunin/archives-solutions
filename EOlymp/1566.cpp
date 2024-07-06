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
        return binPow(x, p - 1, mod) * (x % mod) % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

bool solve() {
    long long a, p;
    cin >> a >> p;

    if (a == -1)
        return 0;

    if (a % p == 0 || binPow(a, (p - 1) / 2, p) == 1)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}