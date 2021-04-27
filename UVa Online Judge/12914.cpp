#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1711276033;

vector<long long> getF() {
    vector<long long> f = { 1 };
    for (int i = 1; i <= 100010; i++)
        f.push_back(f.back() * i % MOD);
    return f;
}

long long binPow(long long x, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x % MOD;
    long long r = binPow(x, p / 2);
    return r * r % MOD;
}

long long inv(long long x) {
    return binPow(x, MOD - 2);
}

long long calc(int n, int m) {
    static vector<long long> f = getF();

    long long res = f[n - m];
    res = res * m % MOD;
    res = res * (m + 1) % MOD;
    res = res * f[n] % MOD;
    res = res * inv(2) % MOD;
    res = res * inv(f[n - m + 1]) % MOD;

    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    for (int m = 1; m <= n; m++)
        cout << calc(n, m) << (m + 1 <= n ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}