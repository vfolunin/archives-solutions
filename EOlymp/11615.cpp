#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1 % mod;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

long long inv(long long x, long long mod) {
    return binPow(x, mod - 2, mod);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wallSize, wallCount, colorCount;
    cin >> wallSize >> wallCount >> colorCount;

    const long long MOD = 1e9 + 7;

    long long wallColorCount = binPow(colorCount, wallSize * wallSize, MOD);
    long long houseColorCount = 0;
    for (int i = 0; i < wallCount; i++)
        houseColorCount = (houseColorCount + binPow(wallColorCount, gcd(i, wallCount), MOD)) % MOD;
    houseColorCount = houseColorCount * inv(wallCount, MOD) % MOD;

    cout << houseColorCount;
}