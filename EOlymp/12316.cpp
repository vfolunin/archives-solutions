#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

vector<long long> precalcFactorials() {
    vector<long long> memo(2e6);
    memo[0] = 1;
    for (int i = 1; i < memo.size(); i++)
        memo[i] = memo[i - 1] * i % MOD;
    return memo;
}

long long factorial(int n) {
    static vector<long long> memo = precalcFactorials();
    return memo[n];
}

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

long long inv(long long x) {
    return binPow(x, MOD - 2, MOD);
}

long long c(int n, int k) {
    return factorial(n) * inv(factorial(k)) % MOD * inv(factorial(n - k)) % MOD;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y;
    cin >> x >> y;

    long long res = 0;
    for (int count1 = 0; count1 * 2 <= x; count1++) {
        int count2 = (y - count1) / 2;
        if (count1 * 2 + count2 == x && count1 + count2 * 2 == y)
            res = (res + c(count1 + count2, count1)) % MOD;
    }

    cout << res;
}