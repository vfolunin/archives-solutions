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

long long inv(long long x) {
    return binPow(x, MOD - 2);
}

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i % MOD;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;

    long long res = factorial(s.size());
    for (int count : count)
        res = res * inv(factorial(count)) % MOD;

    cout << res;
}