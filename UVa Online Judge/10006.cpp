#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

long long binPow(long long x, long long p, long long m) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1, m) * x % m;
    long long r = binPow(x, p / 2, m);
    return r * r % m;
}

bool isCarmichael(int n) {
    if (isPrime(n))
        return 0;
    for (int a = 2; a < n; a++)
        if (binPow(a, n, n) != a)
            return 0;
    return 1;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    if (isCarmichael(n))
        cout << "The number " << n << " is a Carmichael number.\n";
    else
        cout << n << " is normal.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}