#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

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

    int size, letterCount;
    cin >> size >> letterCount;

    long long res = 0;
    for (int aSize = 1, bSize = size - 1; aSize < size; aSize++, bSize--)
        res = (res + binPow(letterCount, (aSize + 1) / 2 + (bSize + 1) / 2, MOD)) % MOD;

    cout << res;
}