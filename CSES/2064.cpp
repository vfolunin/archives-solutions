#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

long long binPow(long long x, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x % MOD;
    long long r = binPow(x, p / 2);
    return r * r % MOD;
}

long long inv(long long n) {
    return binPow(n, MOD - 2);
}

long long getCatalan(int n) {
    vector<long long> res = { 1 };
    for (int i = 1; i <= n; i++)
        res.push_back(res.back() * (4 * i - 2) % MOD * inv(i + 1) % MOD);
    return res.back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << (n % 2 ? 0 : getCatalan(n / 2));
}